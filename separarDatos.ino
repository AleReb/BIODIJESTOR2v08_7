// ————— Función para separar —————
void separarDatos(const String& mensaje) {
  int inicio = 0;
  int fin;
  int indiceCampo = 0;

  // Recorremos las primeras 4 comas (índices 0, 1, 2, 3)
  while ((fin = mensaje.indexOf(',', inicio)) != -1 && indiceCampo < 4) {
    String parte = mensaje.substring(inicio, fin);
    parte.trim();  // Elimina espacios o '\r\n'

    switch (indiceCampo) {
      case 0: operador   = parte; break;
      case 1: tecnologia = parte; break;
      case 2: sen        = parte; break;
      case 3: conectado  = parte; break;
    }

    indiceCampo++;
    inicio = fin + 1;  // Avanzamos justo después de la coma
  }

  // Si ya leimos 4 comas, el resto es el campo ID
  if (indiceCampo == 4 && inicio < mensaje.length()) {
    ID = mensaje.substring(inicio);
    ID.trim();
  }
}