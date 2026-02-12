
// Función para dibujar el encabezado con texto central personalizado
void drawHeader(const char* centralText) {
  // Dibujar un rectángulo lleno como fondo del encabezado
  u8g2.setDrawColor(1);         // Fondo blanco
  u8g2.drawBox(0, 0, 128, 10);  // Rectángulo del encabezado: ancho completo, altura 10

  // Dibujar un icono "home" a la izquierda
  u8g2.setDrawColor(0);  // Color negro para los iconos

  u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
  u8g2.drawGlyph(3, 10, 68);  // Icono de inicio (home)

  // Dibujar el texto central personalizado
  u8g2.setFont(u8g2_font_6x12_tr);  // Fuente del texto
  u8g2.setCursor(11, 9);            // Centrar el texto horizontalmene
  u8g2.print(ID);
  int textWidth = u8g2.getStrWidth(centralText);  // Obtener el ancho del texto
  u8g2.setCursor((128 - textWidth) / 2, 9);       // Centrar el texto horizontalmente
  u8g2.print(centralText);                        // Imprimir el texto central
  if (menu == true) {
    u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
    u8g2.drawGlyph(117, 9, 66);  // Icono de engranaje
  } else {
    // Verificar si se debe mostrar el icono de señal
    if (conectado == "Conectado") {
      // Medir el ancho del número para ajustar la alineación
      //String numberString = "100";  // receivedNumber; cambiar cuando se use el LTE
      int numberWidth = u8g2.getStrWidth(sen.c_str());
      u8g2.setCursor(118 - numberWidth, 9);  // Ajustar la posición del cursor
      u8g2.print(sen);                       // Imprimir el número
      u8g2.setFont(u8g2_font_waffle_t_all);  // Fuente para iconos
      u8g2.drawGlyph(117, 9, 58037);         // Icono de señal
    } else {
      u8g2.setFont(u8g2_font_open_iconic_embedded_1x_t);
      u8g2.drawGlyph(117, 9, 71);  // Icono de exclamación
    }
  }
  // Restablecer el color de dibujo a blanco para el resto del contenido
  u8g2.setDrawColor(1);
}

// Función para dibujar el pie de página con flechas
void drawFooter() {
  u8g2.setFont(u8g2_font_open_iconic_arrow_2x_t);

  // Definir constantes para el diseño
  int screenWidth = 128;  // Ancho de la pantalla OLED en píxeles
  int arrowWidth = 16;    // Ancho aproximado de cada flecha
  int margin = 5;         // Margen desde los bordes
  int numArrows = 3;      // Número total de flechas

  // Calcular el espacio disponible y posiciones
  int usableWidth = screenWidth - (2 * margin);
  int spacing = (usableWidth - (numArrows * arrowWidth)) / (numArrows - 1);

  int arrowX1 = margin;
  int arrowX2 = margin + arrowWidth + spacing;
  int arrowX3 = arrowX2 + arrowWidth + spacing;

  int arrowY = 68;
  // Dibujar las flechas
  u8g2.setDrawColor(1);
  u8g2.drawGlyph(arrowX1, arrowY, 76);
  u8g2.drawGlyph(arrowX2, arrowY, 76);
  u8g2.drawGlyph(arrowX3, arrowY, 76);
  // Restablecer el color de dibujo a blanco
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setDrawColor(1);
}

// Función para dibujar un rectángulo de sensor
void drawSensorRect(int x_pos, const char* etiqueta, const char* valor_str, int padding_label, int padding_value, int y_label, int y_value) {
  int rect_width = 40;   // Ancho del rectángulo
  int rect_height = 35;  // Alto del rectángulo
  int rect_radius = 4;   // Radio de las esquinas redondeadas

  // Dibujar el rectángulo
  u8g2.setDrawColor(1);  // Fondo blanco
  u8g2.drawRBox(x_pos, 12, rect_width, rect_height, rect_radius);

  u8g2.setDrawColor(0);  // Texto en negro
  u8g2.setFont(u8g2_font_8x13B_tf);
  u8g2.drawStr(x_pos + padding_label, y_label, etiqueta);  // Etiqueta

  u8g2.setFont(u8g2_font_logisoso16_tf);                    // Fuente para valores
  u8g2.drawStr(x_pos + padding_value, y_value, valor_str);  // Valor
}

void displayNodo1() {
  u8g2.clearBuffer();
  drawHeader("NODO 1");

  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // Valores de los sensores convertidos a cadenas lo que se muestra en la caja
  String valor_rect1_str = String(globalPh[0], 1);     // pH con 2 decimales
  String valor_rect2_str = String(tempC_Nodos[0], 1);  // Temperatura con 1 decimal
  String valor_rect3_str = String((int)EC_valueN[0]);  // EC como entero

  // Dibujar los rectángulos de los sensores
  drawSensorRect(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[1], "Temp", valor_rect2_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 24, y_offset + 44);
  // Mensajes de advertencia basados en el valor de pH
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
  if (globalPh[0] < 5.5 || globalPh[0] > 8.5) {
    u8g2.setDrawColor(0);
    u8g2.drawRFrame(1, 12, 40, 35, 8);  // Resaltar el rectángulo de pH
    u8g2.setDrawColor(1);
    u8g2.setCursor(0, 55);
    u8g2.print("Alerta: Fuera de rango");
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Rojo
  } else if (globalPh[0] < 6.0 || globalPh[0] > 8.0) {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("Cuidado: Limite de pH");
    pixels.setPixelColor(0, pixels.Color(255, 200, 0));  // Naranja
  } else {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("OK: pH estable");
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Verde
  }
  pixels.show();  // Actualizar LEDs
  drawFooter();
  u8g2.sendBuffer();
}

void displayNodo2() {
  u8g2.clearBuffer();
  drawHeader("NODO 2");

  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // Valores de los sensores convertidos a cadenas lo que se muestra en la caja
  String valor_rect1_str = String(globalPh[1], 1);     // pH con 2 decimales
  String valor_rect2_str = String(tempC_Nodos[1], 1);  // Temperatura con 1 decimal
  String valor_rect3_str = String((int)EC_valueN[1]);  // EC como entero

  // Dibujar los rectángulos de los sensores
  drawSensorRect(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[1], "Temp", valor_rect2_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 24, y_offset + 44);
  // Mensajes de advertencia basados en el valor de pH
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
  if (globalPh[1] < 5.5 || globalPh[1] > 8.5) {
    u8g2.setDrawColor(0);
    u8g2.drawRFrame(1, 12, 40, 35, 8);  // Resaltar el rectángulo de pH
    u8g2.setDrawColor(1);
    u8g2.setCursor(0, 55);
    u8g2.print("Alerta: Fuera de rango");
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Rojo
  } else if (globalPh[1] < 6.0 || globalPh[1] > 8.0) {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("Cuidado: Limite de pH");
    pixels.setPixelColor(0, pixels.Color(255, 200, 0));  // Naranja
  } else {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("OK: pH estable");
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Verde
  }
  pixels.show();  // Actualizar LEDs
  drawFooter();
  u8g2.sendBuffer();
}

void displayNodo3() {
  u8g2.clearBuffer();
  drawHeader("NODO 3");

  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // Valores de los sensores convertidos a cadenas lo que se muestra en la caja
  String valor_rect1_str = String(globalPh[2], 1);     // pH con 2 decimales
  String valor_rect2_str = String(tempC_Nodos[2], 1);  // Temperatura con 1 decimal
  String valor_rect3_str = String((int)EC_valueN[2]);  // EC como entero

  // Dibujar los rectángulos de los sensores
  drawSensorRect(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[1], "Temp", valor_rect2_str.c_str(), 4, 2, y_offset + 24, y_offset + 44);
  drawSensorRect(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 24, y_offset + 44);
  // Mensajes de advertencia basados en el valor de pH
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
  if (globalPh[2] < 5.5 || globalPh[2] > 8.5) {
    u8g2.setDrawColor(0);
    u8g2.drawRFrame(1, 12, 40, 35, 8);  // Resaltar el rectángulo de pH
    u8g2.setDrawColor(1);
    u8g2.setCursor(0, 55);
    u8g2.print("Alerta: Fuera de rango");
    pixels.setPixelColor(0, pixels.Color(255, 0, 0));  // Rojo
  } else if (globalPh[2] < 6.0 || globalPh[2] > 8.0) {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("Cuidado: Limite de pH");
    pixels.setPixelColor(0, pixels.Color(255, 200, 0));  // Naranja
  } else {
    u8g2.setCursor(0, 55);
    u8g2.setDrawColor(1);
    u8g2.print("OK: pH estable");
    pixels.setPixelColor(0, pixels.Color(0, 255, 0));  // Verde
  }
  pixels.show();  // Actualizar LEDs
  drawFooter();
  u8g2.sendBuffer();
}

void displayMainHOME() {
  u8g2.clearBuffer();
  drawHeader("BIODIGESTOR");

  // Posiciones X para los tres rectángulos
  int x_positions[3] = { 1, 43, 85 };

  // Valores de los sensores convertidos a cadenas (lo que se muestra en la caja)
  String valor_rect1_str = "1";  // Esti
  String valor_rect2_str = "2";  // Temperatura con 1 decimal
  String valor_rect3_str = "3";  // EC como entero

  // Dibujar los rectángulos de los sensores centrando el texto
  drawSensorRectHome(x_positions[0], "NODO", valor_rect1_str.c_str(), 24, 44);
  drawSensorRectHome(x_positions[1], "NODO", valor_rect2_str.c_str(), 24, 44);
  drawSensorRectHome(x_positions[2], "NODO", valor_rect3_str.c_str(), 24, 44);
  u8g2.setDrawColor(1);
  // Mensaje abajo de los triángulos
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
  u8g2.setCursor(3, 55);
  u8g2.print(fecha);
  u8g2.print(" H");
  u8g2.print(hora);
  drawFooter();
  u8g2.sendBuffer();
}

// Función para dibujar un rectángulo de sensor centrando el texto para menus diferentes
void drawSensorRectHome(int x_pos, const char* etiqueta, const char* valor_str, int y_label, int y_value) {
  int rect_width = 40;   // Ancho del rectángulo
  int rect_height = 35;  // Alto del rectángulo
  int rect_radius = 4;   // Radio de las esquinas redondeadas

  // Dibujar el rectángulo
  u8g2.setDrawColor(1);  // Fondo blanco
  u8g2.drawRBox(x_pos, 12, rect_width, rect_height, rect_radius);
  u8g2.setDrawColor(0);  // Texto en negro

  // Dibujar la etiqueta centrada
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente para la etiqueta
  int labelWidth = u8g2.getStrWidth(etiqueta);
  int labelX = x_pos + (rect_width - labelWidth) / 2;
  u8g2.drawStr(labelX, y_label, etiqueta);

  // Dibujar el valor centrado
  u8g2.setFont(u8g2_font_logisoso16_tf);  // Fuente para el valor
  int valueWidth = u8g2.getStrWidth(valor_str);
  int valueX = x_pos + (rect_width - valueWidth) / 2;
  u8g2.drawStr(valueX, y_value, valor_str);
}
//////////////////////////////////////////////////////////////////////// menu de calibracion
void displayMenuA() {
  u8g2.clearBuffer();
  drawHeader("AJUSTES");
  // Posiciones X para los tres rectángulos
  int x_positions[3] = { 1, 43, 85 };
  //  String valorLinea1 = "fechanodo1cal";
  //  String valorLinea2 = "fechanodo2cal";
  //  String valorLinea3 = "fechanodo3cal";
  // Valores para cada rectángulo usando objetos String
  // String valor_rect1_lines[] = { valorLinea1, "2024", "Esta:OK" }; DateTime(F(__DATE__), F(__TIME__))
  String valor_rect1_lines[] = { "Last", fechacalN1, yearcalN1 };
  String valor_rect2_lines[] = { "Last", fechacalN2, yearcalN2 };
  String valor_rect3_lines[] = { "Last", fechacalN3, yearcalN3 };

  // Número de líneas para cada rectángulo
  int num_lines_rect1 = 3;
  int num_lines_rect2 = 3;
  int num_lines_rect3 = 3;

  // Dibujar los rectángulos con múltiples líneas de texto
  drawSensorRectMenu(x_positions[0], "NODO 1", valor_rect1_lines, num_lines_rect1, 22);
  drawSensorRectMenu(x_positions[1], "NODO 2", valor_rect2_lines, num_lines_rect2, 22);
  drawSensorRectMenu(x_positions[2], "NODO 3", valor_rect3_lines, num_lines_rect3, 22);

  u8g2.setDrawColor(1);
  // Mensaje en el pie de página
  // Mensaje sobre de los triángulos
  //u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
  String texto = String(hum) + "% " + String(tempE) + "C";
  // Calcular el ancho del texto
  int textWidth = u8g2.getUTF8Width(texto.c_str());
  // Calcular la posición X para centrar
  int x_centrado = (128 - textWidth) / 2;
  // Establecer la posición Y (por ejemplo, en el centro vertical, 32 píxeles)
  int y_value = 55;
  // Dibujar el texto
  u8g2.setCursor(x_centrado, y_value);
  u8g2.print(texto);
  // u8g2.setCursor(20, 55);
  // u8g2.print(hum);
  // u8g2.print("% ");
  // u8g2.print(tempE);
  // u8g2.print("C");
  drawFooter();
  u8g2.sendBuffer();
}

void drawSensorRectMenu(int x_pos, const char* etiqueta, String valores[], int num_valores, int y_label) {
  int rect_width = 40;   // Ancho del rectángulo
  int rect_height = 36;  // Alto del rectángulo (ajustado para más líneas)
  int rect_radius = 4;   // Radio de las esquinas redondeadas

  // Dibujar el rectángulo
  u8g2.setDrawColor(1);  // Fondo blanco
  u8g2.drawRBox(x_pos, 12, rect_width, rect_height, rect_radius);
  u8g2.setDrawColor(0);  // Texto en negro

  // Dibujar la etiqueta centrada
  u8g2.setFont(u8g2_font_6x12_tf);  // Fuente para la etiqueta
  int labelWidth = u8g2.getStrWidth(etiqueta);
  int labelX = x_pos + (rect_width - labelWidth) / 2;
  u8g2.drawStr(labelX, y_label, etiqueta);

  // Dibujar los valores centrados
  u8g2.setFont(u8g2_font_5x8_tf);  // Fuente para los valores
  int line_spacing = 7;            // Espacio entre líneas
  int start_y = y_label + 8;       // Posición Y inicial para las líneas de valor 10 originalmente

  for (int i = 0; i < num_valores; i++) {
    int valueWidth = u8g2.getStrWidth(valores[i].c_str());
    int valueX = x_pos + (rect_width - valueWidth) / 2;
    int y = start_y + i * line_spacing;
    u8g2.drawStr(valueX, y, valores[i].c_str());
  }
  //u8g2.setFont(u8g2_font_6x10_tf);  // Fuente pequeña
}



void displayNodo1M() {
  u8g2.clearBuffer();
  drawHeader("NODO 1 Cal");

  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // Valores de los sensores convertidos a cadenas
  String valor_rect1_str = String(globalPh[0], 1);
  ;                                                    // pH con 2 decimales
  String valor_rect2_str = "Vol";                      // Texto para el segundo rectángulo
  String valor_rect3_str = String((int)EC_valueN[0]);  // EC como número con decimales

  // Variable para controlar la inversión de colores
  bool invertCentralRect = true;  // Cambia a 'true' para invertir los colores del rectángulo central
  // Dibujar los rectángulos de los sensores
  drawSensorRectMenuCAL(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, false);  //originalmente  , y_offset + 24, y_offset + 44, false
  drawSensorRectMenuCAL(x_positions[1], "CAL", valor_rect2_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, invertCentralRect);
  drawSensorRectMenuCAL(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 22, y_offset + 42, false);
  // Mensajes de advertencia basados en el valor de pH
  drawFooter();
  u8g2.sendBuffer();
}

void displayNodo2M() {
  u8g2.clearBuffer();
  drawHeader("NODO 2 Cal");
  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };
  // Valores de los sensores convertidos a cadenas
  String valor_rect1_str = String(globalPh[1], 1);     // pH con 2 decimales
  String valor_rect2_str = "Vol";                      // Texto para el segundo rectángulo
  String valor_rect3_str = String((int)EC_valueN[1]);  // EC como número con decimales

  // Variable para controlar la inversión de colores
  bool invertCentralRect = true;  // Cambia a 'true' para invertir los colores del rectángulo central
  // Dibujar los rectángulos de los sensores
  drawSensorRectMenuCAL(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, false);
  drawSensorRectMenuCAL(x_positions[1], "CAL", valor_rect2_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, invertCentralRect);
  drawSensorRectMenuCAL(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 22, y_offset + 42, false);

  // Mensajes de advertencia basados en el valor de pH
  drawFooter();
  u8g2.sendBuffer();
}

void displayNodo3M() {
  u8g2.clearBuffer();
  drawHeader("NODO 3 Cal");

  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // Valores de los sensores convertidos a cadenas
  String valor_rect1_str = String(globalPh[2], 1);     // pH con 2 decimales
  String valor_rect2_str = "Vol";                      // Texto para el segundo rectángulo
  String valor_rect3_str = String((int)EC_valueN[2]);  // EC como número con decimales

  // Variable para controlar la inversión de colores
  bool invertCentralRect = true;  // Cambia a 'true' para invertir los colores del rectángulo central

  // Dibujar los rectángulos de los sensores
  drawSensorRectMenuCAL(x_positions[0], "PH", valor_rect1_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, false);
  drawSensorRectMenuCAL(x_positions[1], "CAL", valor_rect2_str.c_str(), 4, 2, y_offset + 22, y_offset + 42, invertCentralRect);
  drawSensorRectMenuCAL(x_positions[2], "EC", valor_rect3_str.c_str(), 4, 0, y_offset + 22, y_offset + 42, false);

  // Mensajes de advertencia basados en el valor de pH
  drawFooter();
  u8g2.sendBuffer();
}


void drawSensorRectMenuCAL(int x_pos, const char* etiqueta, const char* valor_str, int decimales, int unidad, int y_label, int y_value, bool invertColors) {
  int rect_width = 40;   // Ancho del rectángulo
  int rect_height = 35;  // Alto del rectángulo
  int rect_radius = 4;   // Radio de las esquinas redondeadas

  // Establecer los colores según invertColors
  if (invertColors) {
    u8g2.setDrawColor(0);  // Fondo negro
  } else {
    u8g2.setDrawColor(1);  // Fondo blanco
  }

  // Dibujar el rectángulo
  u8g2.drawRBox(x_pos, 12, rect_width, rect_height, rect_radius);

  // Establecer el color del texto
  if (invertColors) {
    u8g2.setDrawColor(1);  // Texto blanco
  } else {
    u8g2.setDrawColor(0);  // Texto negro
  }

  // Dibujar la etiqueta centrada
  u8g2.setFont(u8g2_font_6x10_tf);  // Fuente para la etiqueta
  int labelWidth = u8g2.getStrWidth(etiqueta);
  int labelX = x_pos + (rect_width - labelWidth) / 2;
  u8g2.drawStr(labelX, y_label, etiqueta);
  // Aquí puedes procesar 'valor_str' usando 'decimales' y 'unidad' si es necesario

  // Dibujar el valor centrado
  u8g2.setFont(u8g2_font_logisoso16_tf);  // Fuente para el valor
  int valueWidth = u8g2.getStrWidth(valor_str);
  int valueX = x_pos + (rect_width - valueWidth) / 2;
  u8g2.drawStr(valueX, y_value, valor_str);
}
////////////////////////////////////////////////////////funcion calibracion submenu
void displayNodoCalPH(int nodeIndex, int selectedBlock) {
  // Limpia la pantalla
  u8g2.clearBuffer();

  // 1) Dibuja la cabecera con el número de nodo
  char header[16];
  sprintf(header, "NODO %d Cal", nodeIndex);
  drawHeader(header);  // <- tu función para dibujar la cabecera

  // 2) Definir posiciones horizontales para los 3 bloques
  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // 3) Etiquetas para cada bloque
  const char* blockLabels[3] = { "PH4", "PH7", "PH10" };

  // 4) Dibujar los 3 bloques
  for (int i = 0; i < 3; i++) {
    // i va de 0 a 2
    // El bloque “seleccionado” es el que coincide con (selectedBlock-1)
    bool invertColors = (i != (selectedBlock - 1));

    // Nota: valor_str aquí es igual a blockLabels[i]
    // (puedes poner algo más elaborado si necesitas)
    drawSensorRectMenuCAL2(
      x_positions[i],
      blockLabels[i],  // Etiqueta en la parte superior del bloque
      blockLabels[i],  // Valor que se mostrará en grande
      4, 2,            // Estos parámetros los usabas para decimales/unidad
      y_offset + 24,
      y_offset + 44,
      invertColors);
  }

  // 5) Dibuja el footer (si lo usas)
  drawFooter();

  // 6) Enviar a pantalla
  u8g2.sendBuffer();
}

void drawSensorRectMenuCAL2(
  int x_pos,
  const char* etiqueta,
  const char* valor_str,
  int decimales,
  int unidad,
  int y_label,
  int y_value,
  bool invertColors) {
  int rect_width = 40;
  int rect_height = 35;
  int rect_radius = 4;

  // Establecer los colores según invertColors
  if (invertColors) {
    u8g2.setDrawColor(0);  // Fondo "negro"
  } else {
    u8g2.setDrawColor(1);  // Fondo "blanco"
  }
  // Dibujar el rectángulo
  u8g2.drawRBox(x_pos, 12, rect_width, rect_height, rect_radius);

  // Establecer el color del texto dentro del rectángulo
  if (invertColors) {
    u8g2.setDrawColor(1);  // Texto blanco
  } else {
    u8g2.setDrawColor(0);  // Texto negro
  }

  // Etiqueta pequeña (arriba)
  u8g2.setFont(u8g2_font_6x10_tf);
  int labelWidth = u8g2.getStrWidth(etiqueta);
  int labelX = x_pos + (rect_width - labelWidth) / 2;
  u8g2.drawStr(labelX, y_label, etiqueta);

  // Valor grande
  u8g2.setFont(u8g2_font_logisoso16_tf);
  int valueWidth = u8g2.getStrWidth(valor_str);
  int valueX = x_pos + (rect_width - valueWidth) / 2;
  u8g2.drawStr(valueX, y_value, valor_str);
}


void displayNodoCalEC(int nodeIndex, int selectedBlock) {
  // Limpia la pantalla
  u8g2.clearBuffer();

  // 1) Dibuja la cabecera con el número de nodo
  char header[16];
  sprintf(header, "NODO %d Cal", nodeIndex);
  drawHeader(header);  // <- tu función para dibujar la cabecera

  // 2) Definir posiciones horizontales para los 3 bloques
  int x_offset = 0;
  int y_offset = 0;
  int x_positions[3] = { x_offset + 1, x_offset + 43, x_offset + 85 };

  // 3) Etiquetas para cada bloque
  const char* blockLabels[3] = { "EC0", "EC1314", "EC2500" };
  const char* blockLabelsin[3] = { "0", "1413", "2500" };
  // 4) Dibujar los 3 bloques
  for (int i = 0; i < 3; i++) {
    // i va de 0 a 2
    // El bloque “seleccionado” es el que coincide con (selectedBlock-1)
    bool invertColors = (i != (selectedBlock - 1));

    // Nota: valor_str aquí es igual a blockLabels[i]
    // (puedes poner algo más elaborado si necesitas)
    drawSensorRectMenuCAL2(
      x_positions[i],
      blockLabels[i],    // Etiqueta en la parte superior del bloque
      blockLabelsin[i],  // Valor que se mostrará en grande
      4, 2,              // Estos parámetros los usabas para decimales/unidad
      y_offset + 24,
      y_offset + 44,
      invertColors);
  }
  // 5) Dibuja el footer (si lo usas)
  drawFooter();
  // 6) Enviar a pantalla
  u8g2.sendBuffer();
}



void drawCalStatusThreeBlocks(
  const char* mainTitle,
  String linesBlock1[], int countBlock1,
  String linesBlock2[], int countBlock2,
  String linesBlock3[], int countBlock3) {
  // 1) Limpiar y dibujar cabecera con el título principal
  u8g2.clearBuffer();
  drawHeader(mainTitle);  // <-- tu función para la parte superior

  // Medidas para los bloques
  int rectY = 12;
  int rectH = 40;
  int rectW = 40;  //40 originalmente
  int gapX = 2;
  int radius = 4;
  // Ajusta si quieres más altura (ejemplo: rectH=50)

  // Coordenadas X para los 3 bloques
  int blockX[3];
  blockX[0] = 1;
  blockX[1] = blockX[0] + rectW + gapX;  // ~43
  blockX[2] = blockX[1] + rectW + gapX;  // ~85

  // Bloque 1
  {
    u8g2.setDrawColor(1);
    u8g2.drawRBox(blockX[0], rectY, rectW, rectH, radius);
    u8g2.setDrawColor(0);

    u8g2.setFont(u8g2_font_6x12_tf);
    int lineSpacing = 11;
    int startY = rectY + 14;  //18 originalmente
    for (int i = 0; i < countBlock1; i++) {
      int textWidth = u8g2.getStrWidth(linesBlock1[i].c_str());
      int centerX = blockX[0] + (rectW - textWidth) / 2;
      int posY = startY + i * lineSpacing;
      u8g2.drawStr(centerX, posY, linesBlock1[i].c_str());
    }
  }

  // Bloque 2
  {
    u8g2.setDrawColor(1);
    u8g2.drawRBox(blockX[1], rectY, rectW, rectH, radius);
    u8g2.setDrawColor(0);

    u8g2.setFont(u8g2_font_6x12_tf);
    int lineSpacing = 11;
    int startY = rectY + 14;  //18 originalmente
    for (int i = 0; i < countBlock2; i++) {
      int textWidth = u8g2.getStrWidth(linesBlock2[i].c_str());
      int centerX = blockX[1] + (rectW - textWidth) / 2;
      int posY = startY + i * lineSpacing;
      u8g2.drawStr(centerX, posY, linesBlock2[i].c_str());
    }
  }

  // Bloque 3
  {
    u8g2.setDrawColor(1);
    u8g2.drawRBox(blockX[2], rectY, rectW, rectH, radius);
    u8g2.setDrawColor(0);

    u8g2.setFont(u8g2_font_6x12_tf);
    int lineSpacing = 11;
    int startY = rectY + 14;  //18 originalmente
    for (int i = 0; i < countBlock3; i++) {
      int textWidth = u8g2.getStrWidth(linesBlock3[i].c_str());
      int centerX = blockX[2] + (rectW - textWidth) / 2;
      int posY = startY + i * lineSpacing;
      u8g2.drawStr(centerX, posY, linesBlock3[i].c_str());
    }
  }
}


// Dibuja una barra en la parte inferior (últimos ~8px)
// mostrando "Intento X de Y" o “Time left: NN seg”, etc.
void drawFooterCountdown(int currentAttempt, int maxAttempts, int timeLeft, const char* calibrationLabel) {
  // Asumiendo una pantalla de 128x64
  // El footer ocupara la franja de Y=56 a Y=63 (8px de alto approx)

  // 1) Fondo en blanco (drawBox con color 1 = color de dibujo)
  u8g2.setDrawColor(1);
  u8g2.drawBox(0, 56, 128, 8);  // ancho=128, alto=8 px

  // 2) Texto en negro
  u8g2.setDrawColor(0);
  u8g2.setFont(u8g2_font_5x8_tf);

  // Construir el mensaje. Ejemplo: "Int 2/5  T:4s  pH4"
  char buffer[64];
  snprintf(buffer, sizeof(buffer), "Int %d/%d  T:%ds  %s", currentAttempt, maxAttempts, timeLeft, calibrationLabel);

  // Calcular el ancho del texto para centrarlo
  int textWidth = u8g2.getStrWidth(buffer);
  int x = (128 - textWidth) / 2;
  int y = 63;  // baseline ~63 en pantallas de 64 de alto

  // Dibujar el texto centrado
  u8g2.drawStr(x, y, buffer);
}


void drawWrappedTextInBox(const char* text, int x, int y, int boxWidth, int boxHeight) {
  // Configura la fuente que usaras
  u8g2.setFont(u8g2_font_6x10_tf);

  // Margen interno del recuadro para el texto
  int margin = 4;
  int usableWidth = boxWidth - 2 * margin;

  // Dibuja el rectangulo
  u8g2.drawFrame(x, y, boxWidth, boxHeight);

  // Prepara variables para "wrap"
  int lineSpacing = 10;  // Distancia vertical entre lineas (segun tu fuente)
  int cursorX = x + margin;
  int cursorY = y + margin + lineSpacing;

  // Copiamos 'text' a un buffer modificable
  // (necesario para usar strtok o manipular palabras).
  char buffer[256];
  strncpy(buffer, text, sizeof(buffer));
  buffer[sizeof(buffer) - 1] = '\0';  // asegurar fin de cadena

  // Recorremos cada "token" (palabra) separado por espacios
  char* token = strtok(buffer, " ");
  while (token != NULL) {
    // Medir ancho de la palabra
    int wordWidth = u8g2.getUTF8Width(token);

    // Si no cabe en la linea actual, pasar a siguiente linea
    if (cursorX + wordWidth > x + margin + usableWidth) {
      // Siguiente linea
      cursorX = x + margin;
      cursorY += lineSpacing;
    }

    // Verificar si aun cabe verticalmente
    if (cursorY <= y + boxHeight - margin) {
      // Imprimir la palabra
      u8g2.setCursor(cursorX, cursorY);
      u8g2.print(token);
      // Agregar un espacio despues de cada palabra
      cursorX += wordWidth + u8g2.getUTF8Width(" ");
    } else {
      // Si ya no cabe mas en el recuadro, cortamos la impresion
      break;
    }

    token = strtok(NULL, " ");
  }
}
void animateTransitionScreenIn(const char* msg) {
  // Desplazar el recuadro desde x=128 hasta x=0, en pasos
  for (int offset = 128; offset >= 0; offset -= 8) {
    drawTransitionScreenWithOffset(msg, offset);
    delay(50);  // controla velocidad
  }
}



void drawTransitionScreenWithOffset(const char* msg, int offsetX) {
  // Limpiar buffer antes de dibujar
  u8g2.clearBuffer();

  // 1) Dibuja header y footer fijos (sin offset)
  drawHeader("TRANSICION");
  drawFooter();

  // 2) Dibujar el rectángulo central que se moverá
  //    Supongamos un recuadro de 110px de ancho x 20px de alto,
  //    ubicado en (9,20) cuando offsetX = 0.
  //    Tú ajusta a tus gustos (ver el valor final en tu pantalla).
  int boxX = 9 + offsetX;
  int boxY = 20;
  int boxW = 110;
  int boxH = 30;

  // Llamamos a la función de "word wrap" para el texto
  drawWrappedTextInBox(msg, boxX, boxY, boxW, boxH);

  // Enviar al display
  u8g2.sendBuffer();
}