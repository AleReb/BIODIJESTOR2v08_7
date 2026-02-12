// ========================================================
// Variables de estado principales
// ========================================================
bool home = true;  // Muestra la pantalla principal
//bool menu = false;  // Controla si se está en el menú (por ahora lo usas para "menuA", etc.) en el main para manejo principal
bool ajuste = false;
bool nodo1 = false;
bool nodo2 = false;
bool nodo3 = false;

// Flags de los botones (como ya tienes)
volatile bool btn1Flag = false;
volatile bool btn2Flag = false;
volatile bool btn3Flag = false;


// ========================================================
// Función para actualizar el display
// ========================================================
void updateDisplay() {
  // Si NO estamos en calibración, seguimos con la lógica habitual
  if (menu == true) {
    if (calibrandoPH == false && calibrandoEC == false) {
      if (ajuste == true) {
        displayMenuA();
        imprimirCalibracionesYFechas();
      }
      if (nodo1) displayNodo1M();
      if (nodo2) displayNodo2M();
      if (nodo3) displayNodo3M();
    }
    if (calibrandoPH == true && calibrandoEC == false) {
      displayNodoCalPH(currentNode, selectedBlock);
    }
    if (calibrandoEC == true && calibrandoPH == false) {
      displayNodoCalEC(currentNode, selectedBlock);
    }
  } else {
    if (home) displayMainHOME();
    if (nodo1) displayNodo1();
    if (nodo2) displayNodo2();
    if (nodo3) displayNodo3();
  }
}

// ========================================================
// Manejadores de click "corto" de cada botón
// ========================================================
void clickButton1() {
  SerialUSB.println("BTN 1 CLICK funcion ");
  // Aquí podrías invocar algo, si quieres
}

void clickButton2() {
  SerialUSB.println("BTN 2 CLICK funcion ");
  // Acción al clic corto del botón 2
  // (en este ejemplo, la usamos en checkButtons() para algo más)
}

void clickButton3() {
  SerialUSB.println("BTN 3 CLICK funcion");
  // Acción al clic corto del botón 3
}

// ========================================================
// Manejadores de long click de los botones
// ========================================================
void longClickbutton2() {
  SerialUSB.println("long 2: entro/salgo calibracion");
  animateTransitionScreenIn("Entre menus");
  // Al mantener pulsado el botón 2, activamos/desactivamos
  // el modo de calibración
  nodo1 = false;
  nodo2 = false;
  nodo3 = false;
  menu = !menu;
  calibrandoPH = false;
  calibrandoEC = false;
  calibrando = false;
  ajuste = true;
  if (menu == false) {
    home = true;
  }
 
  btn2Flag = false;  // ADICIÓN
}

void longClickbutton3() {
  SerialUSB.println("long 3 -> CANCELAR y regresar MENU");

  // // Desactivar calibraciones
  // calibrandoPH = false;
  // calibrandoEC = false;
  // calibrando = false;

  // // Forzar la pantalla de menú principal
  // menu = true;    // estamos en modo menú
  // ajuste = true;  // nos aseguramos de que sea el “menú principal” (displayMenuA)
  // nodo1 = false;
  // nodo2 = false;
  // nodo3 = false;
  // Evito el click corto
  btn3Flag = false;  // ADICIÓN
}

// ========================================================
// Interrupciones de los botones (igual que en tu código)
// ========================================================
void button1ISR() {
  //btn1.tick();
  btn1Flag = true;
  SerialUSB.println("BTN 1 CLICK interruptor");
}

void button2ISR() {
  //btn2.tick();
  SerialUSB.println("BTN 2 CLICK interruptor");
  btn2Flag = true;
  if (calibrando == true) {
    calibrando = false;
    cancelado = true;
    SerialUSB.println("cancelado true y calibrando false");
  }else{
    //cancelado = false;
    SerialUSB.println("cancelado false y calibrando:" + String(calibrando) );
  }
}

void button3ISR() {
  SerialUSB.println("BTN 3 CLICK interruptor");
  //btn3.tick();

  btn3Flag = true;
}

// ========================================================
// checkbuttons(): lógica que decide qué hacer
// según estemos o no en calibración
// ========================================================
void checkbuttons() {
  // Si estamos en modo calibración, manejamos la navegación de calibración
  if (menu) {
    if (btn1Flag) {
      btn1.tick();  // Procesar evento
      if (ajuste) {
        currentNode = 1;    // En tu caso, si estás en "nodo3"
        selectedBlock = 1;  // Indica si está resaltado el bloque 1, 2 o 3 1;  // Indica si está resaltado el bloque 1, 2 o 3
        ajuste = false;
        nodo1 = true;
        nodo2 = false;
        nodo3 = false;
      } else {
        if (calibrandoPH == true or calibrandoEC == true) {
          selectedBlock = selectedBlock - 1;  // Indica si está resaltado el bloque 1, 2 o 3 1;  // Indica si está resaltado el bloque 1, 2 o 3
        }
        if (calibrandoEC == false) {
          calibrandoPH = true;
        }
        if (selectedBlock <= 0) {
          selectedBlock = 3;  // Indica si está resaltado el bloque 1, 2 o 3 1;  // Indica si está resaltado el bloque 1, 2 o 3
        }
      }
      SerialUSB.println("BTN1: retrocediendo nodos");
      btn1Flag = false;
      delay(200);
    }


    if (btn2Flag) {
      btn2.tick();
      if (ajuste) {
        currentNode = 2;    // En tu caso, si estás en "nodo3"
        selectedBlock = 1;  // Indica si está resaltado el bloque 1, 2 o 3
        // Desde el menú principal, ir al nodo2
        ajuste = false;
        nodo1 = false;
        nodo2 = true;
        nodo3 = false;
      } else {
        if (calibrandoEC == true or calibrandoPH == true) {
          SerialUSB.println("BTN2: enter");
          
          if (calibrandoEC == true) {
            calibrando = true;
            cancelado = false;
            SerialUSB.println("enter a calibrar EC");
            doCalibrationEC(currentNode, selectedBlock);
          }
          if (calibrandoPH == true) {
            calibrando = true;
            cancelado = false;
            SerialUSB.println("enter a calibrar PH");
            doCalibrationPH(currentNode, selectedBlock);
          }
        } else {
          // Volver al menú principal desde cualquier nodo
          ajuste = true;
          nodo1 = false;
          nodo2 = false;
          nodo3 = false;
          SerialUSB.println("BTN2: Volver al menú principal");
        }
      }
      btn2Flag = false;
      delay(200);
    }
    if (btn3Flag) {
      btn3.tick();
      if (ajuste) {
        currentNode = 3;    // En tu caso, si estás en "nodo3"
        selectedBlock = 1;  // Indica si está resaltado el bloque 1, 2 o 3
        // Desde el menú principal, ir al nodo3
        ajuste = false;
        nodo1 = false;
        nodo2 = false;
        nodo3 = true;
      } else {
        if (ajuste == false && calibrando == false) {
          if (calibrandoEC == true or calibrandoPH == true) {
            selectedBlock = selectedBlock + 1;  // Indica si está resaltado el bloque 1, 2 o 3 1;  // Indica si está resaltado el bloque 1, 2 o 3
          }
          if (calibrandoPH == false) {
            calibrandoEC = true;
          }
          if (selectedBlock >= 4) {
            selectedBlock = 1;  // Indica si está resaltado el bloque 1, 2 o 3 1;  // Indica si está resaltado el bloque 1, 2 o 3
          }
        }
      }
      SerialUSB.println("BTN3: avanzando nodo");
      btn3Flag = false;
      delay(200);
    }
  }

  // =====================================================
  // Si NO estamos calibrando, manejamos tu menú principal
  // =====================================================
  if (btn1Flag) {
    btn1.tick();  // Procesar evento
    if (home) {
      // Desde el menú principal, ir al nodo1
      home = false;
      nodo1 = true;
      nodo2 = false;
      nodo3 = false;
    } else {
      // Navegar al nodo anterior
      if (nodo1) {
        nodo1 = false;
        nodo3 = true;
      } else if (nodo3) {
        nodo3 = false;
        nodo2 = true;
      } else if (nodo2) {
        nodo2 = false;
        nodo1 = true;
      }
    }
    btn1Flag = false;
  }

  if (btn2Flag) {
    btn2.tick();
    if (home) {
      // Desde el menú principal, ir al nodo2
      home = false;
      nodo1 = false;
      nodo2 = true;
      nodo3 = false;
    } else {
      // Volver al menú principal desde cualquier nodo
      home = true;
      nodo1 = false;
      nodo2 = false;
      nodo3 = false;
    }
    btn2Flag = false;
  }

  if (btn3Flag) {
    btn3.tick();
    if (home) {
      // Desde el menú principal, ir al nodo3
      home = false;
      nodo1 = false;
      nodo2 = false;
      nodo3 = true;
    } else {
      // Navegar al nodo siguiente
      if (nodo1) {
        nodo1 = false;
        nodo2 = true;
      } else if (nodo2) {
        nodo2 = false;
        nodo3 = true;
      } else if (nodo3) {
        nodo3 = false;
        nodo1 = true;
      }
    }
    btn3Flag = false;
  }
}
