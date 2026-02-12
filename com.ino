void comunicacion() {
  // // read from port 1, send to port 0: el puerto sofware sercom
  /*
  este bloque era para debugear las salidas seriales
  */
  // if (mySerial.available()) {
  //   data = mySerial.readStringUntil('\n');  // Read data until newline character
  //   data.trim();                            // Remove leading and trailing whitespace

  //   if (data.length() > 0) {  // Check if the message is not empty
  //     SerialUSB.print("Received: ");
  //     SerialUSB.println(data);  // Print the received data to SerialUSB
  //   }
  // }

  // // read from port 0, send to port 1:
  // if (SerialUSB.available()) {
  //   uint8_t inByte = SerialUSB.read();
  //   mySerial.write(inByte);
  // }

  /*
  mySerial es el serial que revisa los datos de la rpi, se usa una funcion para evitar dobles puntos o caracteres raros que dan problema en la transferencia
  de datos.

  while (mySerial.available() > 0) {
    char incomingChar = mySerial.read();

    // Debug: Uncomment to print each received character
    SerialUSB.print("Received char: ");
    SerialUSB.println(incomingChar);

    // Check for newline character indicating end of message
    if (incomingChar == '\n') {
      inputBuffer[bufferIndex] = '\0';  // Null-terminate the string

      // Convert inputBuffer to String
      String dataLocal = String(inputBuffer);

      // Validate the data
      if (isValidData(dataLocal)) {
        // Data is valid, process it
        SerialUSB.print("Received valid data: ");
        SerialUSB.println(dataLocal);  // Print the received data
        data = dataLocal;
        // TODO: Add your data processing logic here
      } else {
        // Data is invalid, set data to 'x'
        SerialUSB.println("Invalid data received, setting data to 'x'");
        data = "x";
      }

      // Reset buffer index for next message
      bufferIndex = 0;
    } else {
      // If not newline, add character to buffer if there's space
      if (bufferIndex < BUFFER_SIZE - 1) {
        inputBuffer[bufferIndex++] = incomingChar;
      } else {
        // Buffer overflow, reset buffer and index
        bufferIndex = 0;
        SerialUSB.println("Buffer overflow, discarding data.");
      }
    }
  }
*/
  //placa madre modem: el puerto fisico solo recive numeros enteros
  if (Serial1.available()) {
    static String dataFromModem = "";
    char c = Serial1.read();
    SerialUSB.print("Received from Modem: ");
    SerialUSB.println(c);  // Print the received data
    if (c == '\n') {
      dataFromModem.trim();  // Remove any leading or trailing whitespace
      if (dataFromModem.length() > 0) {
        // SerialUSB.print("Received from Modem: ");
        // SerialUSB.println(dataFromModem);  // Print the received data
        // Now, since the data is supposed to be an integer number, parse it
        int receivedNumberINT = dataFromModem.toInt();  // Convert string to integer
        if (receivedNumberINT < 1) {
          showSignalIcon = false;
        } else {
          numberString = String(receivedNumberINT);
          showSignalIcon = true;
        }
        receivedNumber = String(receivedNumberINT);
        SerialUSB.print("Parsed integer: ");
        SerialUSB.println(receivedNumber);
        // Reset the data string for the next message
        dataFromModem = "";
      }
    } else {
      dataFromModem += c;
    }
  }
}