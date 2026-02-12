// Adicionamos un parámetro 'bool isPhSensor' para diferenciar pH de EC.


void calibration(uint16_t calibrationType,
                 uint8_t sensorPin,
                 bool isPhSensor,
                 uint16_t numSamples = 60,
                 float stabilityThreshold = unitTreshold,
                 uint16_t maxStabilityAttempts = 100) {
  SerialUSB.println("Iniciando estabilizacion...");

  // Construye una etiqueta de calibracion (ej. "pH4", "pH7", "EC1413", etc.)
  char calibrationLabel[16];
  if (isPhSensor) {
    if (calibrationType == 4) strcpy(calibrationLabel, "pH4");
    else if (calibrationType == 7) strcpy(calibrationLabel, "pH7");
    else if (calibrationType == 10) strcpy(calibrationLabel, "pH10");
    else strcpy(calibrationLabel, "pH?");
  } else {
    if (calibrationType == 0) strcpy(calibrationLabel, "EC0");
    else if (calibrationType == 1413) strcpy(calibrationLabel, "EC1413");
    else if (calibrationType == 2500) strcpy(calibrationLabel, "EC2500");
    else strcpy(calibrationLabel, "EC?");
  }

  while (calibrando) {
    uint32_t sum = 0;
    bool isStable = false;
    int stabilityAttempt = 0;
    float voltage = 0;
    int countdown = 5;

    // ====================================
    // 1) Esperar estabilidad
    // ====================================
    while (!isStable && stabilityAttempt < maxStabilityAttempts && calibrando) {
      int prevReading = analogRead(sensorPin);
      delay(1000);
      int currentReading = analogRead(sensorPin);

      voltage = map_float(currentReading, 0, 4095, 0, 3300) / 1000.0;
      int diff = abs(currentReading - prevReading);

      // Mostrar info en 3 bloques
      {
        String block1[] = { "Volt:", String(voltage, 3) + "V" };
        String block2[] = { "Estab:", String(diff) };
        String block3[] = { "Atmp:", String(stabilityAttempt) };

        String nodoESTA = "ESTAB NODO " + String(nodeIndex);
        drawCalStatusThreeBlocks(
          nodoESTA.c_str(),
          block1, 2,
          block2, 2,
          block3, 2);
      }

      // Pequeña cuenta regresiva con etiqueta de calibracion
      for (int i = countdown; i >= 0 && calibrando; i--) {
        // Nota: i se usa como "tiempoRestante" en el footer
        drawFooterCountdown(stabilityAttempt, maxStabilityAttempts, i, calibrationLabel);
        u8g2.sendBuffer();
        delay(1000);
      }

      // Chequeamos si la diferencia de lecturas está bajo el umbral
      if (diff <= stabilityThreshold) {
        isStable = true;
      }
      stabilityAttempt++;
    }  // fin while (!isStable...)

    // ====================================
    // 2) Revisar si se logró estabilizar
    // ====================================
    if (!isStable) {
      // Mostramos un mensaje de fallo en la pantalla
      String block1[] = { "Fallo" };
      String block2[] = { "en", "Estabilizar" };
      String block3[] = { "Cancel" };

      drawCalStatusThreeBlocks(
        "SIN EXITO",
        block1, 1,
        block2, 2,
        block3, 1);
      delay(2000);
      calibrando = false;
      break;  // Terminamos la calibración si no hay estabilidad
    } else {
      // ====================================
      // 3) Éxito en estabilizar, tomar muestras
      // ====================================
      {
        String block1[] = { "OK" };
        String block2[] = { "Volt:", String(voltage, 3) + " V" };
        String block3[] = { "Estable" };
        drawCalStatusThreeBlocks(
          "ESTABIL. OK",
          block1, 1,
          block2, 2,
          block3, 1);
      }
      SerialUSB.println("Estabilizacion exitosa!");

      for (int i = 0; i < numSamples && calibrando; i++) {
        int rawReading = analogRead(sensorPin);
        sum += rawReading;

        // Calcula la media provisional (hasta la muestra i)
        float provisionalVoltage = (sum / float(i + 1)) / 4095.0 * 3.3;

        // Mostrar info en 3 bloques mientras tomamos muestras
        String block1[] = {
          "Mstr:", String(i + 1) + "/" + String(numSamples)
        };
        String block2[] = {
          "Volt:", String(provisionalVoltage, 4)
        };
        String block3[] = {
          "Faltan:", String(numSamples - (i + 1))
        };

        String nodoCAL = "CAL NODO " + String(nodeIndex);
        drawCalStatusThreeBlocks(
          nodoCAL.c_str(),
          block1, 2,
          block2, 2,
          block3, 2);

        // Uso de "i" como "tiempoRestante" es simbólico, puedes ajustar si gustas
        drawFooterCountdown(i, numSamples, 1, calibrationLabel);
        u8g2.sendBuffer();
        delay(1000);
      }

      // Calcular el voltaje final tras la toma de muestras
      float finalVoltage = (float)sum / (float)numSamples / 4095.0 * 3.3;
      //SerialUSB.println("antes de guardar");
      actualizarFecha = true;
      // *** AQUÍ ES DONDE HACEMOS LA ACTUALIZACION REAL DE LA CALIBRACION ***
      // Ajusta el nodeIndex, pues en tu código parece que nodeIndex va de 1..N, mientras que
      // calibracionActual[] es 0-based.
      // Si nodeIndex ya es 0-based, solo usa nodeIndex. Si es 1-based, usa nodeIndex - 1.
      if(cancelado == false){
      actualizarCalibracion(nodeIndex - 1,  // O nodeIndex, según tu lógica
                            isPhSensor,
                            finalVoltage,    // Valor de voltaje promedio
                            calibrationType  // 4,7,10 o 0,1413,2500
      );
      SerialUSB.println("GUARDADO");
      animateTransitionScreenIn("CALIBRACION OK Y GUARDANDO");
      }else{
        animateTransitionScreenIn("CALIBRACION CANCELADA");
      }
      calibrandoPH = false;
      calibrandoEC = false;
      calibrando = false;
      // Vuelvo al menú principal
      menu = true;
      ajuste = true;
      nodo1 = false;
      nodo2 = false;
      nodo3 = false;
      home = false;
      break;  // Fin de calibración exitosa
    }
  }  // fin while(calibrando)
}

void doCalibrationEC(int currentNode, int selectedBlock) {
  nodeIndex = currentNode;
  int pinIndex = currentNode - 1;  // again, assuming nodeIndex is 1-based

  switch (selectedBlock) {
    case 1:  // EC0
      SerialUSB.println("Starting calibration for EC0...");
      calibrando = true;
      calibration(0, ecPins[pinIndex], false /* isPhSensor = false */);
      break;

    case 2:  // EC 1413
      SerialUSB.println("Starting calibration for EC1413...");
      calibrando = true;
      calibration(1413, ecPins[pinIndex], false);
      break;

    case 3:  // EC 2500
      SerialUSB.println("Starting calibration for EC2500...");
      calibrando = true;
      calibration(2500, ecPins[pinIndex], false);
      break;

    default:
      SerialUSB.println("Error: Invalid EC calibration block selected.");
      break;
  }
}

void doCalibrationPH(int currentNode, int selectedBlock) {
  // nodeIndex might be a global or static variable used inside calibration(...)
  // If nodeIndex is 1-based, the array indexes are 0-based in calibracionActual[].
  nodeIndex = currentNode;

  // This is just an example if you have an array of pins for pH sensors, e.g. phPins[]
  int pinIndex = currentNode - 1;

  // Decide which calibration type (4, 7, or 10) based on selectedBlock
  switch (selectedBlock) {
    case 1:  // pH 4
      SerialUSB.println("Starting calibration for pH4...");
      calibrando = true;  // Set global flag indicating we are in calibration mode
      calibration(4, phPins[pinIndex], true /* isPhSensor = true */);
      break;

    case 2:  // pH 7
      SerialUSB.println("Starting calibration for pH7...");
      calibrando = true;
      calibration(7, phPins[pinIndex], true);
      break;

    case 3:  // pH 10
      SerialUSB.println("Starting calibration for pH10...");
      calibrando = true;
      calibration(10, phPins[pinIndex], true);
      break;

    default:
      SerialUSB.println("Error: Invalid pH calibration block selected.");
      break;
  }
}
