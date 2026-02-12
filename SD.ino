// Función para guardar los datos en el archivo CSV
void guardarDatos() {
  File myFile = SD.open(archivo, FILE_WRITE);
  // Escribir los datos si el archivo se abrió correctamente
  if (myFile) {
    String lineaDatos = fecha + "," + hora + "," + String(tempE) + "," + String(hum) + "," + 
    String(tempC_Nodos[0]) + "," + String(globalPh[0]) + "," + "," + String((int)EC_valueN[0]) + "," + 
                        String(tempC_Nodos[1]) + "," + String(globalPh[1]) + "," + String((int)EC_valueN[1]) + "," + 
                        String(tempC_Nodos[2])+ "," + String(globalPh[2]) + "," + String((int)EC_valueN[2]),ID;  
    myFile.println(lineaDatos);  // Escribir la línea de datos
    myFile.close();              // Cerrar el archivo
    SerialUSB.println("Datos guardados en el archivo CSV.");
  } else {
    SerialUSB.println("Error al abrir el archivo para escribir.");
  }
}