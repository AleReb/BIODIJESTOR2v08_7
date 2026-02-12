#include <FlashStorage.h>

////////////////////////////// nueva flash
// Estructura para guardar los datos de calibración de un nodo
struct Calibracion {
  float ph4;
  float ph7;
  float ph10;
  float ec0;
  float ec1413;
  float ec2500;
  // Date fields
  char fecha[12];  // e.g. "MM/DD" or "DD/MM"
  char year[12];   // e.g. "YYYY"
};

// Instancias de FlashStorage para cada nodo
FlashStorage(nodo1Calibracion, Calibracion);
FlashStorage(nodo2Calibracion, Calibracion);
FlashStorage(nodo3Calibracion, Calibracion);
FlashStorage(sensorMapStorage, SensorMap);

// Variables en memoria para trabajar con las calibraciones actuales
Calibracion calibracionActual[8];

void cargarValoresPredeterminados(int nodoIndex) {
  SerialUSB.print("Cargando valores predeterminados para nodo ");
  SerialUSB.println(nodoIndex + 1);

  switch (nodoIndex) {
    case 0:
      calibracionActual[0] = {
        defaultVoltage_ph4[0],
        defaultVoltage_ph7[0],
        defaultVoltage_ph10[0],
        defaultVoltage_ec0[0],
        defaultVoltage_ec1413[0],
        defaultVoltage_ec2500[0]
      };

      // // Fecha/Year por defecto para nodo 1:
      strcpy(calibracionActual[0].fecha, currentDateCompi.c_str());  // DD/MM
      strcpy(calibracionActual[0].year, currentYearCompi.c_str());   // YYYY
                                                                     // Mostrar la fecha y el año
      fechacalN1 = currentDateCompi;                                 // "DD/MM"
      yearcalN1 = currentYearCompi;                                  // "YYYY"
      SerialUSB.print("nodo 1  Fecha: ");
      SerialUSB.println(calibracionActual[nodoIndex].fecha);
      SerialUSB.print("  Año: ");
      SerialUSB.println(calibracionActual[nodoIndex].year);


      break;

    case 1:
      calibracionActual[1] = {
        defaultVoltage_ph4[1],
        defaultVoltage_ph7[1],
        defaultVoltage_ph10[1],
        defaultVoltage_ec0[1],
        defaultVoltage_ec1413[1],
        defaultVoltage_ec2500[1]
      };

      // // Fecha/Year por defecto para nodo 2:
      strcpy(calibracionActual[1].fecha, currentDateCompi.c_str());  // DD/MM
      strcpy(calibracionActual[1].year, currentYearCompi.c_str());   // YYYY
                                                                     // Mostrar la fecha y el año
      fechacalN2 = currentDateCompi;                                 // "DD/MM"
      yearcalN2 = currentYearCompi;                                  // "YYYY"
      SerialUSB.print("nodo 2  Fecha: ");
      SerialUSB.println(calibracionActual[nodoIndex].fecha);
      SerialUSB.print("  Año: ");
      SerialUSB.println(calibracionActual[nodoIndex].year);


      break;

    case 2:
      calibracionActual[2] = {
        defaultVoltage_ph4[2],
        defaultVoltage_ph7[2],
        defaultVoltage_ph10[2],
        defaultVoltage_ec0[2],
        defaultVoltage_ec1413[2],
        defaultVoltage_ec2500[2]
      };

      // // Fecha/Year por defecto para nodo 3:
      strcpy(calibracionActual[2].fecha, currentDateCompi.c_str());  // DD/MM
      strcpy(calibracionActual[2].year, currentYearCompi.c_str());   // YYYY
        // Mostrar la fecha y el año
      fechacalN3 = currentDateCompi;  // "DD/MM"
      yearcalN3 = currentYearCompi;   // "YYYY"
      SerialUSB.print("nodo 3   Fecha: ");
      SerialUSB.println(calibracionActual[nodoIndex].fecha);
      SerialUSB.print("  Año: ");
      SerialUSB.println(calibracionActual[nodoIndex].year);

      break;

    default:
      SerialUSB.println("Error: Nodo inválido.");
      return;
  }

  SerialUSB.println("Valores predeterminados cargados:");
  SerialUSB.print("  pH4: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph4);
  SerialUSB.print("  pH7: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph7);
  SerialUSB.print("  pH10: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph10);
  SerialUSB.print("  EC0: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec0);
  SerialUSB.print("  EC1413: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec1413);
  SerialUSB.print("  EC2500: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec2500);
  // Mostrar la fecha y el año
  SerialUSB.print("  Fecha: ");
  SerialUSB.println(calibracionActual[nodoIndex].fecha);
  SerialUSB.print("  Año: ");
  SerialUSB.println(calibracionActual[nodoIndex].year);
}


void guardarCalibracionNodo(int nodoIndex) {
  SerialUSB.print("Guardando calibración para nodo ");
  SerialUSB.println(nodoIndex + 1);
  if (actualizarFecha) {
    // 3) Guardar en tus variables globales (fechacalN1, etc.)
    if (nodoIndex == 0) {
      fechacalN1 = currentDate;  // "DD/MM"
      yearcalN1 = currentYear;   // "YYYY"
      SerialUSB.print("Entre en nodo idex  de guardar calibracion 1  Fecha: ");
      SerialUSB.println(fechacalN1);
      SerialUSB.print("  Year: ");
      SerialUSB.println(yearcalN1);
    } else if (nodoIndex == 1) {
      fechacalN2 = currentDate;
      yearcalN2 = currentYear;
      SerialUSB.print("Entre en nodo idex de guardar calibracion 2  Fecha: ");
      SerialUSB.println(fechacalN2);
      SerialUSB.print("  Year: ");
      SerialUSB.println(yearcalN2);
    } else if (nodoIndex == 2) {
      fechacalN3 = currentDate;
      yearcalN3 = currentYear;
      SerialUSB.print("Entre en nodo idex de guardar calibracion 3  Fecha: ");
      SerialUSB.println(fechacalN3);
      SerialUSB.print("  Year: ");
      SerialUSB.println(yearcalN3);
    }

    // Store these date strings in calibracionActual
    strcpy(calibracionActual[nodoIndex].fecha, currentDate.c_str());
    strcpy(calibracionActual[nodoIndex].year, currentYear.c_str());
  }
  switch (nodoIndex) {
    case 0:
      nodo1Calibracion.write(calibracionActual[0]);
      break;
    case 1:
      nodo2Calibracion.write(calibracionActual[1]);
      break;
    case 2:
      nodo3Calibracion.write(calibracionActual[2]);
      break;
    default:
      SerialUSB.println("Error: Nodo inválido.");
      return;
  }

  SerialUSB.println("Calibración guardada exitosamente.");
  SerialUSB.print("  pH4: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph4);
  SerialUSB.print("  pH7: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph7);
  SerialUSB.print("  pH10: ");
  SerialUSB.println(calibracionActual[nodoIndex].ph10);
  SerialUSB.print("  EC0: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec0);
  SerialUSB.print("  EC1413: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec1413);
  SerialUSB.print("  EC2500: ");
  SerialUSB.println(calibracionActual[nodoIndex].ec2500);
  SerialUSB.print("  Fecha: ");
  SerialUSB.println(calibracionActual[nodoIndex].fecha);
  SerialUSB.print("  Year: ");
  SerialUSB.println(calibracionActual[nodoIndex].year);
}

void actualizarCalibracion(int nodoIndex, bool isPhSensor, float value, int calibrationType) {
  SerialUSB.print("Actualizando calibración para nodo ");
  SerialUSB.println(nodoIndex + 1);

  if (isPhSensor) {
    SerialUSB.print("  Tipo: pH ");
    switch (calibrationType) {
      case 4:
        calibracionActual[nodoIndex].ph4 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (pH4)");
        break;
      case 7:
        calibracionActual[nodoIndex].ph7 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (pH7)");
        break;
      case 10:
        calibracionActual[nodoIndex].ph10 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (pH10)");
        break;
      default:
        SerialUSB.println("  Error: Tipo de calibración pH inválido.");
        return;
    }
  } else {
    SerialUSB.print("  Tipo: EC");
    switch (calibrationType) {
      case 0:
        calibracionActual[nodoIndex].ec0 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (EC0)");
        break;
      case 1413:
        calibracionActual[nodoIndex].ec1413 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (EC1413)");
        break;
      case 2500:
        calibracionActual[nodoIndex].ec2500 = value;
        SerialUSB.print(value);
        SerialUSB.println("  (EC2500)");
        break;
      default:
        SerialUSB.println("  Error: Tipo de calibración EC inválido.");
        return;
    }
  }
  SerialUSB.print("  calibrationType = ");
  SerialUSB.println(calibrationType);
  SerialUSB.print("  Valor recibido: ");
  SerialUSB.println(value, 4);
  // Guardar los cambios en memoria Flash
  actualizarFecha = true;
  guardarCalibracionNodo(nodoIndex);
}

void cargarCalibraciones() {
  calibracionActual[0] = nodo1Calibracion.read();
  calibracionActual[1] = nodo2Calibracion.read();
  calibracionActual[2] = nodo3Calibracion.read();

  SerialUSB.println("Leídos desde Flash:");
  for (int i = 0; i < 3; i++) {
    SerialUSB.print("Nodo ");
    SerialUSB.print(i + 1);
    SerialUSB.println(":");
    SerialUSB.print("  pH4: ");
    SerialUSB.println(calibracionActual[i].ph4);
    SerialUSB.print("  pH7: ");
    SerialUSB.println(calibracionActual[i].ph7);
    SerialUSB.print("  pH10: ");
    SerialUSB.println(calibracionActual[i].ph10);
    SerialUSB.print("  EC0: ");
    SerialUSB.println(calibracionActual[i].ec0);
    SerialUSB.print("  EC1413: ");
    SerialUSB.println(calibracionActual[i].ec1413);
    SerialUSB.print("  EC2500: ");
    SerialUSB.println(calibracionActual[i].ec2500);
    SerialUSB.print("  Fecha: ");
    SerialUSB.println(calibracionActual[i].fecha);
    SerialUSB.print("  Year: ");
    SerialUSB.println(calibracionActual[i].year);

    // Asigna la fecha a la variable global correspondiente:
    if (i == 0) {
      fechacalN1 = calibracionActual[i].fecha;
      yearcalN1 = calibracionActual[i].year;
      SerialUSB.print("Asignada Fecha/Year a nodo 1: ");
      SerialUSB.print(fechacalN1);
      SerialUSB.print(" / ");
      SerialUSB.println(yearcalN1);
    } else if (i == 1) {
      fechacalN2 = calibracionActual[i].fecha;
      yearcalN2 = calibracionActual[i].year;
      SerialUSB.print("Asignada Fecha/Year a nodo 2: ");
      SerialUSB.print(fechacalN2);
      SerialUSB.print(" / ");
      SerialUSB.println(yearcalN2);
    } else if (i == 2) {
      fechacalN3 = calibracionActual[i].fecha;
      yearcalN3 = calibracionActual[i].year;
      SerialUSB.print("Asignada Fecha/Year a nodo 3: ");
      SerialUSB.print(fechacalN3);
      SerialUSB.print(" / ");
      SerialUSB.println(yearcalN3);
    }
  }

  // Ajusta la variable de bucle interno para que no reescriba "i"
  for (int j = 0; j < 3; j++) {
    if (calibracionActual[j].ph4 == 0) {
      SerialUSB.print("Nodo ");
      SerialUSB.print(j + 1);
      SerialUSB.println(": Valores no válidos en memoria. Cargando predeterminados.");
      // Cargar valores predeterminados
      cargarValoresPredeterminados(j);
      // Desactivar la actualización de fecha para que no cambie la fecha al sobrescribir
      actualizarFecha = false;
      // Guardar los valores predeterminados
      guardarCalibracionNodo(j);
    }
  }
}


void imprimirCalibracionesYFechas() {
  SerialUSB.println("=== Calibraciones y Fechas (struct) por Nodo ===");
  for (int i = 0; i < 3; i++) {
    // Imprime "Nodo X" y termina esa línea:
    SerialUSB.print("Nodo ");
    SerialUSB.print(i + 1);

    // Imprime los campos de calibración, cada uno con su salto de línea:
    SerialUSB.print("  pH4:     ");
    SerialUSB.print(calibracionActual[i].ph4, 4);

    SerialUSB.print("  pH7:     ");
    SerialUSB.print(calibracionActual[i].ph7, 4);

    SerialUSB.print("  pH10:    ");
    SerialUSB.print(calibracionActual[i].ph10, 4);

    SerialUSB.print("  EC0:     ");
    SerialUSB.print(calibracionActual[i].ec0, 4);

    SerialUSB.print("  EC1413:  ");
    SerialUSB.print(calibracionActual[i].ec1413, 4);

    SerialUSB.print("  EC2500:  ");
    SerialUSB.print(calibracionActual[i].ec2500, 4);

    SerialUSB.print("  Fecha:   ");
    SerialUSB.print(calibracionActual[i].fecha);

    SerialUSB.print("  Año:    ");
    SerialUSB.println(calibracionActual[i].year);

    // No pongas SerialUSB.println(); extra aquí
  }
  SerialUSB.println();

  // SerialUSB.println("=== Fechas Globales (String) ===");
  // SerialUSB.print("N1 - fecha: ");
  // SerialUSB.println(fechacalN1);
  // SerialUSB.print("N1 - year:  ");
  // SerialUSB.println(yearcalN1);

  // SerialUSB.print("N2 - fecha: ");
  // SerialUSB.println(fechacalN2);
  // SerialUSB.print("N2 - year:  ");
  // SerialUSB.println(yearcalN2);

  // SerialUSB.print("N3 - fecha: ");
  // SerialUSB.println(fechacalN3);
  // SerialUSB.print("N3 - year:  ");
  // SerialUSB.println(yearcalN3);

  // SerialUSB.println("================================");
}
