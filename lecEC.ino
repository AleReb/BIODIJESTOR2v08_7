void readEC() {
  // Reiniciar sumas y conteos
  for (int node = 0; node < numSensors; node++) {
    sumVoltageEC_Nodos[node] = 0.00;
    sampleCountEC_Nodos[node] = 0;
  }

  // Tomar muestras
  for (int i = 0; i < numSamplesLec; i++) {
    for (int node = 0; node < numSensors; node++) {
      int rawValue = analogRead(ecPins[node]);
      // Convertir a voltaje asumiendo rango 0-4400 (ajusta si corresponde a tu hardware)
      float voltage = (rawValue * maxVEC) / 4400.0;
      sumVoltageEC_Nodos[node] += voltage;
      sampleCountEC_Nodos[node]++;
    }
    delay(5);  // Ajustar si se requiere un delay
  }

  // Calcular promedio por sensor
  for (int node = 0; node < numSensors; node++) {
    if (sampleCountEC_Nodos[node] > 0) {
      averageVoltageEC_Nodos[node] = sumVoltageEC_Nodos[node] / sampleCountEC_Nodos[node];
    } else {
      averageVoltageEC_Nodos[node] = 0.0;
    }
  }

  // Calcular EC por interpolación a partir de los puntos de calibración
  for (int node = 0; node < numSensors; node++) {
    // ---------------------------------------------------------------------------------
    // 1) Obtener las referencias desde calibracionActual (o donde las tengas) o default
    // ---------------------------------------------------------------------------------
    // Supongamos que calibracionActual[node].ec0, ec1413, ec2500 existen.
    float v0     = calibracionActual[node].ec0;
    float v1413  = calibracionActual[node].ec1413;
    float v2500  = calibracionActual[node].ec2500;
    float measuredV = averageVoltageEC_Nodos[node];

    bool usedDefault = false;
    // Si no es válido (<= 0), usamos default
    if (v0 <= 0) {
      v0 = defaultVoltage_ec0[node];
      usedDefault = true;
    }
    if (v1413 <= 0) {
      v1413 = defaultVoltage_ec1413[node];
      usedDefault = true;
    }
    if (v2500 <= 0) {
      v2500 = defaultVoltage_ec2500[node];
      usedDefault = true;
    }
if(debugSENSOR == true){
    // Depuración: imprimir referencias que se usan
    SerialUSB.print("Nodo EC ");
    SerialUSB.print(node);
    SerialUSB.print(" -> v0: ");
    SerialUSB.print(v0, 4);
    SerialUSB.print(", v1413: ");
    SerialUSB.print(v1413, 4);
    SerialUSB.print(", v2500: ");
    SerialUSB.print(v2500, 4);

    if (usedDefault) {
      SerialUSB.println("  (usando default en alguno)");
    } else {
      SerialUSB.println("  (usando valores de Flash)");
    }
}
    // ---------------------------------------------------------------------------------
    // 2) Interpolar
    // ---------------------------------------------------------------------------------
    float ecVal = 0.0;
    if (measuredV <= v1413) {
      // Tramo 0 - 1413
      if ((v1413 - v0) != 0) {
        ecVal = ((measuredV - v0) / (v1413 - v0)) * 1413.0;
      } else {
        ecVal = 0.0;
      }
    } else {
      // Tramo 1413 - 2500
      if ((v2500 - v1413) != 0) {
        ecVal = 1413.0 + ((measuredV - v1413) / (v2500 - v1413)) * (2500.0 - 1413.0);
      } else {
        ecVal = 1413.0;
      }
    }

    if (ecVal < 0) ecVal = 0;
    EC_valueN[node] = ecVal;

    // ---------------------------------------------------------------------------------
    // 3) Mensaje final de depuración
    // ---------------------------------------------------------------------------------
    if(debugSENSOR == true){
    SerialUSB.print("Nodo EC ");
    SerialUSB.print(node);
    SerialUSB.print(": Voltaje promedio = ");
    SerialUSB.print(measuredV, 4);
    SerialUSB.print(" V -> EC = ");
    SerialUSB.print(EC_valueN[node], 2);
    SerialUSB.println(" uS/cm");
    }
  }
if(debugSENSOR == true){
  SerialUSB.println("Lectura completa de EC.\n");
}
}
