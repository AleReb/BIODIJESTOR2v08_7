void readPh3() {
  unsigned long currentMillisph = millis();
  // Tomar lecturas solo cada 50 ms
  if (currentMillisph - previousMillisPH >= intervalMillisph) {
    previousMillisPH = currentMillisph;

    // Leer cada sensor de pH
    for (int i = 0; i < numPHs; i++) {
      int pH_raw = analogRead(phPins[i]);
      float voltage = map(pH_raw, 0, 4095, 0, 3300) / 1000.0;  // de raw a voltios
      sumVoltagePH[i] += voltage;
      sampleCountPH[i]++;
      if (debugSENSOR == true) {
        // Mensajes de depuración de la lectura actual
        SerialUSB.print("Sensor pH ");
        SerialUSB.print(i);
        SerialUSB.print(" - Lectura cruda: ");
        SerialUSB.print(pH_raw);
        SerialUSB.print(" -> Voltaje: ");
        SerialUSB.print(voltage, 4);
        SerialUSB.print(" V, pH calculado anterior: ");
        SerialUSB.print(globalPh[i], 2);
        SerialUSB.print(" (Muestra #");
        SerialUSB.print(sampleCountPH[i]);
        SerialUSB.println(")");
      }
      // Si tenemos suficientes muestras, calcular promedio y el valor de pH
      if (sampleCountPH[i] >= numSamplesLecph) {
        averageVoltagePH[i] = sumVoltagePH[i] / numSamplesLecph;

        // Reiniciamos sumas y contadores
        sumVoltagePH[i] = 0.0;
        sampleCountPH[i] = 0;
        if (debugSENSOR == true) {
          SerialUSB.print("Sensor pH ");
          SerialUSB.print(i);
          SerialUSB.print(" - Voltaje promedio: ");
          SerialUSB.print(averageVoltagePH[i], 4);
          SerialUSB.print(" V -> ");
        }
        // -------------------------------
        // 1) Obtener valores de calibracion (Flash o defecto)
        // -------------------------------
        float v4 = calibracionActual[i].ph4;
        float v7 = calibracionActual[i].ph7;
        float v10 = calibracionActual[i].ph10;

        // Verificar validez (ajusta tu criterio si lo necesitas)
        // Por ejemplo, consideramos "inválido" si <= 0.
        bool usadoDefault = false;

        if (v4 <= 0) {
          v4 = defaultVoltage_ph4[i];
          usadoDefault = true;
        }
        if (v7 <= 0) {
          v7 = defaultVoltage_ph7[i];
          usadoDefault = true;
        }
        if (v10 <= 0) {
          v10 = defaultVoltage_ph10[i];
          usadoDefault = true;
        }
        if (debugSENSOR == true) {
          // Depuración: imprimir cuáles valores se usaron
          SerialUSB.print("\n  Referencias pH para sensor ");
          SerialUSB.print(i);
          SerialUSB.print(" -> v4: ");
          SerialUSB.print(v4, 4);
          SerialUSB.print(" | v7: ");
          SerialUSB.print(v7, 4);
          SerialUSB.print(" | v10: ");
          SerialUSB.print(v10, 4);

          if (usadoDefault) {
            SerialUSB.println("  (usando default para alguno de ellos)");
          } else {
            SerialUSB.println("  (usando valores de Flash)");
          }
        }
        // -------------------------------
        // 2) Realizar la interpolación / extrapolación
        // -------------------------------
        if (averageVoltagePH[i] > v4 + epsilon) {
          // Extrapolar para pH < 4
          globalPh[i] = 4.00 - (4.00 - 0.00) * (averageVoltagePH[i] - v4) / (3.3f - v4);
          SerialUSB.print("Extrapolando pH < 4");
        } else if (averageVoltagePH[i] <= v4 + epsilon && averageVoltagePH[i] >= v7 - epsilon) {
          // Interpolar entre pH 4 y pH 7
          globalPh[i] = 4.00 + (7.00 - 4.00) * (v4 - averageVoltagePH[i]) / (v4 - v7);
          SerialUSB.print("Interpolando entre pH 4 y 7");
        } else if (averageVoltagePH[i] < v7 + epsilon && averageVoltagePH[i] >= v10 - epsilon) {
          // Interpolar entre pH 7 y pH 10
          globalPh[i] = 7.00 + (10.00 - 7.00) * (v7 - averageVoltagePH[i]) / (v7 - v10);
          SerialUSB.print("Interpolando entre pH 7 y 10");
        } else if (averageVoltagePH[i] < v10 - epsilon) {
          // Extrapolar para pH > 10
          globalPh[i] = 10.00 + (14.00 - 10.00) * (v10 - averageVoltagePH[i]) / (v10 - 0.0);
          SerialUSB.print("Extrapolando pH > 10");
        } else {
          globalPh[i] = -1;  // Error o fuera de rango
          SerialUSB.print("Error: Voltaje fuera de rango");
        }

        // Limitar pH entre 0 y 14
        globalPh[i] = constrain(globalPh[i], 0.0, 14.0);

        // -------------------------------
        // 3) Mostrar el resultado final
        // -------------------------------
        if (debugSENSOR == true) {
          SerialUSB.print(" -> pH calculado: ");
          SerialUSB.println(globalPh[i], 2);
        }
      }
    }
  }
  // Esta función no retorna nada, pero globalPh[] contiene los valores de pH
  // más recientes para cada sensor.
}
