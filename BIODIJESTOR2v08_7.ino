#define logoc_width 60
#define logoc_height 50
static unsigned char logoC[] = {
  0xff, 0x8f, 0xff, 0xff, 0xff, 0xf1, 0xff, 0x0f, 0xff, 0x03, 0xfc, 0xff,
  0x7f, 0xc0, 0xff, 0x0f, 0xff, 0x01, 0xf8, 0xff, 0x1f, 0x80, 0xff, 0x0f,
  0xff, 0x00, 0xe0, 0xff, 0x07, 0x00, 0xff, 0x0f, 0x7f, 0x00, 0x00, 0xff,
  0x00, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f,
  0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f,
  0xff, 0x00, 0x00, 0xff, 0x00, 0x00, 0xfe, 0x0f, 0xff, 0x00, 0xe0, 0xff,
  0x07, 0x00, 0xff, 0x0f, 0xff, 0x01, 0xf8, 0xff, 0x1f, 0x80, 0xff, 0x0f,
  0xff, 0x03, 0xfe, 0xff, 0x7f, 0xc0, 0xff, 0x0f, 0xff, 0x8f, 0xff, 0xff,
  0xff, 0xf1, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
  0x3f, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xcf, 0x0f, 0x07, 0xf8, 0xff, 0x00,
  0xff, 0xff, 0x03, 0x0e, 0x03, 0xf0, 0x7f, 0x00, 0xfe, 0xff, 0x00, 0x0c,
  0x01, 0xe0, 0x3f, 0x00, 0xf8, 0x7f, 0x00, 0x08, 0x01, 0xe0, 0x3f, 0x00,
  0xc0, 0x0f, 0x30, 0x08, 0x01, 0xe0, 0x3f, 0x00, 0x00, 0x00, 0x30, 0x00,
  0x00, 0xc0, 0x1f, 0x00, 0x00, 0x00, 0xfc, 0x01, 0x00, 0xc0, 0x1f, 0x00,
  0x00, 0x00, 0xfc, 0x01, 0x00, 0xc0, 0x3f, 0x00, 0x00, 0x00, 0x30, 0x00,
  0x01, 0xe0, 0x3f, 0x00, 0x80, 0x07, 0x30, 0x00, 0x01, 0xe0, 0x3f, 0x00,
  0xf8, 0x3f, 0x20, 0x08, 0x03, 0xf0, 0x7f, 0x00, 0xfe, 0xff, 0x00, 0x0c,
  0x07, 0xf8, 0xff, 0x00, 0xff, 0xff, 0x01, 0x0e, 0x1f, 0xfe, 0xff, 0xc3,
  0xff, 0xff, 0x87, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0f,
  0xff, 0xdf, 0xff, 0xff, 0xff, 0xfb, 0xff, 0x0f, 0xff, 0x03, 0xfe, 0xff,
  0x7f, 0xc0, 0xff, 0x0f, 0xff, 0x01, 0xf8, 0xff, 0x1f, 0x80, 0xff, 0x0f,
  0xff, 0x00, 0xe0, 0xff, 0x07, 0x00, 0xff, 0x0f, 0xff, 0x00, 0x80, 0xff,
  0x01, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f,
  0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00,
  0x00, 0x00, 0xfe, 0x0f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfe, 0x0f,
  0x7f, 0x00, 0x00, 0x3c, 0x00, 0x00, 0xfe, 0x0f, 0xff, 0x00, 0xc0, 0xff,
  0x07, 0x00, 0xff, 0x0f, 0xff, 0x01, 0xf8, 0xff, 0x1f, 0x00, 0xff, 0x0f,
  0xff, 0x03, 0xfc, 0xff, 0x3f, 0xc0, 0xff, 0x0f, 0xff, 0x0f, 0xff, 0xff,
  0xff, 0xe0, 0xff, 0x0f
};
/*
  Base para placa monitoreo biodijestor V2, se esta usando un samd21 por tener mejores AD y manejar mas pines
  se esta comprobando el uso de los puertos ADC y pines digitales para el uso de diferentes sensores extras que se puedan necesitar

*/
bool debugSENSOR = false;    ///////////////////////////////// data show spam true para mostrar el spam de mensajes de EC y PH
#include <Arduino.h>         // required before wiring_private.h
#include "wiring_private.h"  // pinPeripheral() function
#include <SPI.h>
#include <SD.h>
String nombreVer = "BioDiges V0.8.7";
const char* archivo = "biov1.csv";  // Nombre del archivo
bool SDok = false;
#include <OneButton.h>
// Configuración de los pines para los botones
// Configuración de los pines para los botones
#define BUTTON_PIN_1 8   // Pin 8 para el primer botón
#define BUTTON_PIN_2 12  // Pin para el segundo botón
#define BUTTON_PIN_3 13  // Pin para el segundo botón
// Instancias de OneButton para cada botón
OneButton btn1(BUTTON_PIN_1, true);  // Primer botón: activo bajo, con resistencia externa
OneButton btn2(BUTTON_PIN_2, true);  // Segundo botón: activo bajo, con resistencia externa
OneButton btn3(BUTTON_PIN_3, true);  // Segundo botón: activo bajo, con resistencia externa

// Configuración del RTC
#include <RTClib.h>
bool rtcOK = false;
bool dht22OK = false;
RTC_DS3231 rtc;
String fecha;
String hora;
String data = "x";

#include <OneWire.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS 5
#define MAX_SENSORS 8  // Máximo de sensores a manejar
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
// ——— Estructura y FlashStorage para el mapeo ———
struct SensorMap {
  uint8_t count;
  DeviceAddress addr[MAX_SENSORS];
};

// ——— Variables globales ———
uint8_t sensorCount = 0;
DeviceAddress sensorMapArr[MAX_SENSORS];
float tempC_Nodos[MAX_SENSORS];

//float tempC_Nodos[] = { 0.00, 0.00, 0.00 };  // temperatura para cada ds18b20
#include "DHT.h"
#define DHTPIN 7       // Digital pin connected to the DHT sensor
#define DHTTYPE DHT22  // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);
float hum;
float tempE;

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif
// Which pin on the Arduino is connected to the NeoPixels?
#define PIN 3  // On Trinket or Gemma, suggest changing this to 1
// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1  // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//////////////////////////////variables calibracion EC y PH
int sampleCountEC = 0;
float sumVoltageEC = 0.0;
float averageVoltageEC = 0.0;

// Variables para compensación de temperatura
const float temp_ref = 25.0;  // Temperatura de referencia en °C
const float alpha_EC = 0.02;  // Coeficiente de temperatura para EC (2% por °C)

/////////////////////// para la funcion calibracion
int numSamples = 60;             // Número de muestras para el promedio durante la calibración
float stabilityThreshold = 1.0;  // Umbral de estabilidad
#define unitTreshold 5
////////////////////////////////milis de mensajes y guardado
// Nueva variable para indicar si estamos en "modo calibración"
int nodeIndex = 0;
bool calibrando = false;
bool calibrandoPH = false;
bool calibrandoEC = false;
bool menu = false;                                   // Controla si se está en el menú (por ahora lo usas para "menuA", etc.)
int currentNode = 0;                                 // En tu caso depende del nodo
int selectedBlock = 0;                               // Indica si está resaltado el bloque 1, 2 o 3
unsigned long menuSpam = 0;                          // Variable para llevar un registro del último guardado y conexion
const unsigned long intervalomenuSpam = 6000;        // Intervalo de Lectura dht extra
unsigned long ultimoGuardado = 0;                    // Variable para llevar un registro del último guardado y conexion
const unsigned long intervaloGuardado = 60000 * 10;  // Intervalo de guardado SD (60 segundos en milisegundos) 60000 * 3
unsigned long checktemp = 0;                         // Variable para llevar la temperatura
const unsigned long interchecktemp = 6000;           // Intervalo LECTURA  DHT
unsigned long spamMensaje = 0;                       // Variable para llevar
const unsigned long interspamMensaje = 10000;        // Intervalo LECTURA  ESTABILIDAD
float PH_valueN[] = { 0.00, 0.00, 0.00 };            // PH nodo 1, 2, 3

//senñal de red celular
String numberString = "0";
int signalQuality;
bool showSignalIcon = true;  // variable de conexion

int analog_pin_1 = A0;  // PH nodo 1
int analog_pin_2 = A1;  // PH nodo 2
int analog_pin_3 = A2;  // PH nodo 3
int analog_pin_4 = A3;  // EC nodo 1
int analog_pin_5 = A4;  // EC nodo 2
int analog_pin_6 = A5;  // EC nodo 3
/*
Pin mappings for SAMD21:
A0 = 14
A1 = 15
A2 = 16
A3 = 17
A4 = 18
A5 = 19
*/

// Pines de cada sensor EC
int phPins[] = { analog_pin_1, analog_pin_2, analog_pin_3 };
// Valores de calibración predeterminados para cada sensor de pH
float defaultVoltage_ph4[] = { 2.0460, 2.0460, 2.0460 };  // Valores para sensores 1, 2, 3
float defaultVoltage_ph7[] = { 1.5350, 1.5350, 1.5350 };
float defaultVoltage_ph10[] = { 1.1140, 1.1140, 1.1140 };

int numSamplesLecph = 40;  // Número de muestras para el promedio
int numPHs = 3;
// Epsilon para evitar problemas de flotantes
float epsilon = 0.001;
// Variables para almacenamiento de datos de cada sensor pH
float sumVoltagePH[3] = { 0.0, 0.0, 0.0 };
float averageVoltagePH[3] = { 0.0, 0.0, 0.0 };
int sampleCountPH[3] = { 0, 0, 0 };
float globalPh[3] = { -1.0, -1.0, -1.0 };
// Variables para control de tiempo
unsigned long previousMillisPH = 0;
unsigned long intervalMillisph = 50;  // leer cada 50 ms


// Valores de calibración predeterminados para cada sensor de EC

float defaultVoltage_ec0[] = { 0.0040, 0.0053, 0.0182 };     // EC nodo 1, 2, 3
float defaultVoltage_ec1413[] = { 0.7805, 0.7864, 0.0837 };  // EC nodo 1, 2, 3
float defaultVoltage_ec2500[] = { 1.3731, 1.3340, 0.1434 };  // EC nodo 1, 2, 3
float defaultVoltage_ec12880[] = { 4, 4, 0.8501 };
// Variables globales para EC de cada nodo
int sampleCountEC_Nodos[] = { 0, 0, 0 };
float sumVoltageEC_Nodos[] = { 0.00, 0.00, 0.00 };
float averageVoltageEC_Nodos[] = { 0.00, 0.00, 0.00 };
float EC_valueN[] = { 0.00, 0.00, 0.00 };  // EC para cada sensor

// Pines de cada sensor EC
int ecPins[] = { analog_pin_4, analog_pin_5, analog_pin_6 };
const int numSensors = 3;  // Numero de sensores EC
// Variables de lectura
int EC_raw[numSensors];        // Valores crudos de los sensores
float EC_voltage[numSensors];  // Valores convertidos a voltaje
// Variables de tiempo
unsigned long previousMillisEC = 0;
const unsigned long intervalMillis = 50;  // intervalo de muestreo
// Constantes generales (ajustar según tu hardware)
float maxVEC = 3.3;      // Máximo voltaje esperado
int numSamplesLec = 40;  // Número de muestras para el promedio

/////////////////////////////////////////////////////////////////// recepcion de datos
int receivedNumberINT;
String receivedNumber;

// ————— Variables globales —————
String operador;
String tecnologia;
String sen;
String conectado;
String ID = "5";  /////////////////////////////////////////////////////////////////////////////////////////////ID del dispositivo
/////////////////////////////////////

// Buffer for incoming serial data
#define BUFFER_SIZE 64
char inputBuffer[BUFFER_SIZE];
uint8_t bufferIndex = 0;

Uart mySerial(&sercom1, 11, 10, SERCOM_RX_PAD_0, UART_TX_PAD_2);
void SERCOM1_Handler() {
  mySerial.IrqHandler();
}

#include <U8g2lib.h>
#include <Wire.h>
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

File myFile;

String fechacalN1;
String yearcalN1;
String fechacalN2;
String yearcalN2;
String fechacalN3;
String yearcalN3;

String currentDate = "";  // "DD/MM"
String currentYear = "";  // "YYYY"

String currentDateCompi = "";  // "DD/MM"
String currentYearCompi = "";  // "YYYY"

#define logoc_width 60
#define logoc_height 50
/////////////////// bools de calibracion generales
bool actualizarFecha = false;  // Flag para controlar la actualización de fecha
bool cancelado = false;
void setup() {
  // Extraer la fecha y el año de __DATE__
  currentYearCompi = String(__DATE__).substring(7, 11);  // Los caracteres del índice 7 al 11 son el año
  currentDateCompi = getFormattedDateFromCompileTime();

  // initialize both serial ports:
  SerialUSB.begin(115200);
  Serial1.begin(9600);  //pines 0 y 1 fisicos
  // Inicializa Serial2 el myserial es el serial #sercom#
  mySerial.begin(9600);
  // Assign pins 11 & 10 SERCOM functionality
  pinPeripheral(10, PIO_SERCOM);
  pinPeripheral(11, PIO_SERCOM);

  // Configurar los pines de los botones como entradas (sin pull-up interno)
  pinMode(BUTTON_PIN_1, INPUT);
  pinMode(BUTTON_PIN_2, INPUT);
  pinMode(BUTTON_PIN_3, INPUT);
  // Asignar interrupciones a cada botón
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN_1), button1ISR, CHANGE);  // Interrupción en cambio de estado para el botón 1
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN_2), button2ISR, CHANGE);  // Interrupción en cambio de estado para el botón 2
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN_3), button3ISR, CHANGE);  // Interrupción en cambio de estado para el botón 3
  // Configuración de botones con la librería OneButton
  btn1.attachClick(clickButton1);              // Asignar función para clic simple del botón 1
  btn2.attachClick(clickButton2);              // Asignar función para clic simple del botón 2
  btn3.attachClick(clickButton3);              // Asignar función para clic simple del botón 2
  btn2.attachLongPressStop(longClickbutton2);  // Asignar función para pulsación larga del botón 2
  btn2.setPressTicks(1000);                    // Tiempo en milisegundos para considerar una pulsación larga (1000 ms)
  btn3.attachLongPressStop(longClickbutton3);  // Asignar función para pulsación larga del botón 3
  btn3.setPressTicks(1000);                    // Tiempo en milisegundos para considerar una pulsación larga (1000 ms)
  // Configurar el tiempo de debounce personalizado (en milisegundos)
  btn1.setDebounceTicks(200);  // Tiempo de debounce para el botón 1
  btn2.setDebounceTicks(200);  // Tiempo de debounce para el botón 2
  btn3.setDebounceTicks(200);  // Tiempo de debounce para el botón 3
  pixels.begin();              // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.setPixelColor(0, pixels.Color(0, 0, 255));
  pixels.show();  // Send the updated pixel colors to the hardware.
  u8g2.begin();
  u8g2.setDisplayRotation(U8G2_R2);  // R0: normal, R1: 90°, R2: 180°, R3: 270°
  u8g2.setDrawColor(0);              // Establece el color de dibujo a negro
                                     // u8g2.drawXBMP(0, 0, logoc_width, logoc_height, logoC);
  //u8g2.sendBuffer();

  int centerX = (128 - logoc_width) / 2;  // Centrar en X
  int centerY = (64 - logoc_height) / 2;  // Centrar en Y
  int startY = 64;                        // Inicia fuera de la pantalla (abajo)
  for (int y = startY; y >= centerY; y--) {
    u8g2.clearBuffer();                                           // Limpiar el buffer
    u8g2.drawXBMP(centerX, y, logoc_width, logoc_height, logoC);  // Dibujar logo
    u8g2.sendBuffer();                                            // Enviar contenido al OLED
    delay(20);                                                    // Controlar la velocidad del movimiento
  }
  u8g2.setDrawColor(1);  // Establece el color de dibujo a negro
  delay(2000);


  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_8x13_tf);
  u8g2.setCursor(0, 13);
  u8g2.print(nombreVer);
  u8g2.setCursor(0, 24);
  u8g2.print("Inicializando");
  // Enviar el buffer a la pantalla
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.sendBuffer();
  // Start up the library ds19b20
  sensors.begin();
  delay(2000);
  // Check how many sensors are connected
  sensors.begin();
  updateSensorMap();
  SerialUSB.print("Sensores mapeados: ");
  SerialUSB.println(sensorCount);
  for (uint8_t i = 0; i < sensorCount; i++) {
    SerialUSB.print(" Nodo ");
    SerialUSB.print(i);
    SerialUSB.print(": ");
    printAddress(sensorMapArr[i]);
    SerialUSB.println();
  }

  int deviceCount = sensors.getDeviceCount();
  SerialUSB.print("Number of temperature sensors found: ");
  SerialUSB.println(deviceCount);
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setCursor(0, 34);
  u8g2.print("Temp found: " + String(deviceCount));
  // Enviar el buffer a la pantalla
  u8g2.sendBuffer();

  if (!rtc.begin()) {
    SerialUSB.println("Couldn't find RTC");
    SerialUSB.flush();
  } else {
    rtcOK = true;
  }
  dht.begin();
  analogReadResolution(12);  // set ADC to 12-bit
  SerialUSB.print("Initializing SD card...");
  if (!SD.begin(9)) {
    SerialUSB.println("initialization failed!");
  } else {
    SDok = true;
    SerialUSB.println("initialization done.");
    // Verificar si el archivo existe
    if (!SD.exists(archivo)) {
      SerialUSB.println("Archivo no existe, creando nuevo archivo...");
      File myFile = SD.open(archivo, FILE_WRITE);

      // Escribir la cabecera del archivo CSV
      if (myFile) {
        myFile.println("FECHA,HORA,TEMPERATURA EXTERIOR,HUMEDAD, TEMPERATURA AGUA1 , PH1 , EC1, TEMPERATURA AGUA2 , PH2 , EC2, TEMPERATURA AGUA3 , PH3 , EC3, ID");
        myFile.close();
        SerialUSB.println("Cabecera del archivo CSV creada correctamente.");
      } else {
        SerialUSB.println("Error al crear el archivo.");
      }
    } else {
      SerialUSB.println("El archivo ya existe.");
    }
  }

  if (readDHT22()) {
    SerialUSB.println("Lectura DHT exitosa");
    dht22OK = true;
  } else {
    SerialUSB.println("Error: Lectura DHT fallida.");
  }
  if (dht22OK) {
    u8g2.setCursor(60, 43);
    u8g2.print("DHT OK");
  } else {
    u8g2.setCursor(60, 43);
    u8g2.print("DHT FAIL");
  }
  if (rtcOK) {
    u8g2.setCursor(0, 43);
    u8g2.print("RTC OK");
  } else {
    u8g2.setCursor(0, 43);
    u8g2.print("RTC FAIL");
  }
  if (SDok) {
    u8g2.setCursor(0, 53);
    u8g2.print("SD OK");
  } else {
    u8g2.setCursor(0, 53);
    u8g2.print("SD FAIL");
  }
  u8g2.sendBuffer();
  pixels.setPixelColor(0, pixels.Color(0, 255, 0));
  pixels.show();  // Send the updated pixel colors to the hardware.
    // Cargar calibraciones desde memoria Flash
  cargarCalibraciones();
  delay(3000);
}


#define DHT_READ_RETRIES 3   // Número de reintentos de lectura
#define DHT_RETRY_DELAY 500  // Retraso en milisegundos entre reintentos

// Función para leer el sensor DHT con reintentos
bool readDHT22() {
  bool success = false;
  for (int i = 0; i < DHT_READ_RETRIES; i++) {
    hum = dht.readHumidity();
    tempE = dht.readTemperature();

    // Comprobar si la lectura es válida
    if (!isnan(hum) && !isnan(tempE)) {
      success = true;
      break;  // Lectura exitosa
    }
    // Si la lectura falla, espera un momento y reintenta
    delay(DHT_RETRY_DELAY);
  }
  return success;
}


void loop() {
  if (sensorCount < 3) {
    sensors.begin();
    updateSensorMap();
    SerialUSB.print("Sensores mapeados: ");
    SerialUSB.println(sensorCount);
    for (uint8_t i = 0; i < sensorCount; i++) {
      SerialUSB.print(" Nodo ");
      SerialUSB.print(i);
      SerialUSB.print(": ");
      printAddress(sensorMapArr[i]);
      SerialUSB.println();
    }

    int deviceCount = sensors.getDeviceCount();
    SerialUSB.print("Number of temperature sensors found: ");
    SerialUSB.println(deviceCount);
  }
  unsigned long currentMillis = millis();  // Obtener el tiempo actual en milisegundos
  btn1.tick();
  btn2.tick();
  btn3.tick();
  // Actualizamos la pantalla
  updateDisplay();
  checkbuttons();
  if (menu == true) {
    SerialUSB.println("Cal NODO: " + String(currentNode) + " bloque: " + String(selectedBlock));
    if (calibrandoEC == true) SerialUSB.println(" EN CAL EC");
    if (calibrandoPH == true) SerialUSB.println(" EN CAL PH");
    if (currentMillis - menuSpam >= intervalomenuSpam) {
      menuSpam = currentMillis;  // Intentar leer los datos del DHT
      SerialUSB.println("En menu de calibracion");
      if (readDHT22()) {
        // SerialUSB.println("Lectura DHT exitosa");
      } else {
        SerialUSB.println("Error: Lectura DHT fallida.");
      }
    }
  } else {
    readEC();
    readPh3();
    comunicacion();
  }

  // Lectura de sensores DHT y temperatura cada 3 segundos (ejemplo)
  if (currentMillis - checktemp >= interchecktemp) {
    checktemp = currentMillis;  // Actualizar el tiempo de última lectura
    // Intentar leer los datos del DHT
    if (readDHT22()) {
      // SerialUSB.println("Lectura DHT exitosa");
    } else {
      SerialUSB.println("Error: Lectura DHT fallida.");
    }
    // Leer temperatura del agua
    sensors.requestTemperatures();
    delay(300);
    //tempC = sensors.getTempCByIndex(0);
    //tempC_Nodos[0] = sensors.getTempCByIndex(0);
    //tempC_Nodos[1] = sensors.getTempCByIndex(1);
    //tempC_Nodos[2] = sensors.getTempCByIndex(2);
    tempC_Nodos[0] =  sensors.getTempC(sensorMapArr[0]);
    tempC_Nodos[1] =  sensors.getTempC(sensorMapArr[1]);
    tempC_Nodos[2] =  sensors.getTempC(sensorMapArr[2]);


    // Construir y mostrar la linea de salida
    String sensores = "";
    sensores += String(tempC_Nodos[0]) + " tE1 " + String(tempC_Nodos[1]) + " tE2 " + String(tempC_Nodos[2]) + " tE3 " + String(hum) + " humE " + String(tempC_Nodos[0]) + " A " + String(tempC_Nodos[1]) + " B " + String(tempC_Nodos[2]) + " C " + fecha + " " + hora;
    // Mostrar los valores
    //String sensores = String(tempE) + " tE " + String(hum) + " humE " + String(tempC) + " tempAgua";
    SerialUSB.println(sensores);
  }


  sensors.requestTemperatures();  // Send the command to get temperatures


  // Leer y mostrar la fecha y hora del RTC
  DateTime now = rtc.now();
  fecha = getFecha(now);
  hora = getHora(now);
  currentDate = getFechaCorta(now);  // "DD/MM"
  currentYear = getAno(now);         // "YYYY"

  // Guardar datos en la SD cada 3 minutos (180,000 ms)
  if (currentMillis - ultimoGuardado >= intervaloGuardado) {
    ultimoGuardado = currentMillis;  // Actualizar el tiempo de último guardado
    guardarDatos();                  // Función que guarda los datos en el archivo CSV
    SerialUSB.println("Datos guardados en la SD.");
  }
  // Enviar mensajes periódicos (cada 30 segundos en este caso)
  if (currentMillis - spamMensaje >= interspamMensaje) {
    // Verificar si los valores son NaN o si son -125.00 (indicando un valor inválido), y sustituir por "x"
    String humStr = isnan(hum) || hum == -125.00 ? "x" : String(hum);
    String tempEStr = isnan(tempE) || tempE == -125.00 ? "x" : String(tempE);
    String tempCStr0 = (isnan(tempC_Nodos[0]) || tempC_Nodos[0] == -125.00) ? "x" : String(tempC_Nodos[0]);
    String tempCStr1 = (isnan(tempC_Nodos[1]) || tempC_Nodos[1] == -125.00) ? "x" : String(tempC_Nodos[1]);
    String tempCStr2 = (isnan(tempC_Nodos[2]) || tempC_Nodos[2] == -125.00) ? "x" : String(tempC_Nodos[2]);
    String phStr0 = (isnan(globalPh[0]) || globalPh[0] == -125.00) ? "x" : String(globalPh[0]);
    String phStr1 = (isnan(globalPh[1]) || globalPh[1] == -125.00) ? "x" : String(globalPh[1]);
    String phStr2 = (isnan(globalPh[2]) || globalPh[2] == -125.00) ? "x" : String(globalPh[2]);
    String ecStr0 = (isnan(EC_valueN[0]) || EC_valueN[0] == -125) ? "x" : String((int)EC_valueN[0]);
    String ecStr1 = (isnan(EC_valueN[1]) || EC_valueN[1] == -125) ? "x" : String((int)EC_valueN[1]);
    String ecStr2 = (isnan(EC_valueN[2]) || EC_valueN[2] == -125) ? "x" : String((int)EC_valueN[2]);

    spamMensaje = currentMillis;  // Actualizar el tiempo de último mensaje

    // Formar la línea de datos con los valores corregidos
    String lineaDatos = tempEStr + "," + humStr + "," + tempCStr0 + "," + phStr0 + "," + ecStr0 + "," + tempCStr1 + "," + phStr1 + "," + ecStr1 + "," + tempCStr2 + "," + phStr2 + "," + ecStr2, ID;

    SerialUSB.println("Enviando mensaje periódico... " + lineaDatos);
    // Serial1.println(lineaDatos);
    mySerial.println(lineaDatos);  // placa madre manda datos a través de aquí
    // Aquí puedes poner la lógica para enviar un mensaje o realizar alguna acción periódica.
  }
  if (mySerial.available()) {
    String mensaje2 = mySerial.readStringUntil('\n');  // Display the Receivers characters
    // Llamar a la función para separar y almacenar los datos
    separarDatos(mensaje2);
    SerialUSB.println("recivido: " + mensaje2);
    // Para verificar:
    SerialUSB.println("operador: " + operador);
    SerialUSB.println("tecnologia: " + tecnologia);
    SerialUSB.println("señal: " + sen);
    SerialUSB.println("Registrado: " + conectado);
    SerialUSB.println("ID: " + ID);
    yield();
  }
}

///////////////////////////////////////////////// fin del loop
String getFecha(DateTime now) {
  char fecha[11];
  sprintf(fecha, "%02d/%02d/%04d", now.day(), now.month(), now.year());
  return String(fecha);
}

String getHora(DateTime now) {
  char hora[9];
  sprintf(hora, "%02d:%02d:%02d", now.hour(), now.minute(), now.second());
  return String(hora);
}

// Function to validate received data
bool isValidData(String data) {
  // Check if the data is empty
  if (data.length() == 0) {
    return false;
  }

  int dotCount = 0;    // Counter for dots
  int minusCount = 0;  // Counter for minus signs

  // Iterate over each character to check if it's valid
  for (size_t i = 0; i < data.length(); i++) {
    char c = data.charAt(i);

    // Check for valid characters
    if (!isDigit(c) && c != '-' && c != '.') {
      return false;  // Invalid character found
    }

    // Count dots
    if (c == '.') {
      dotCount++;
    }

    // Count minus signs
    if (c == '-') {
      minusCount++;

      // Ensure minus sign is only at the first position
      if (i != 0) {
        return false;  // Minus sign not at the start, invalid data
      }
    }
  }
  // Check if there is more than one dot
  if (dotCount > 1) {
    return false;  // More than one dot, invalid data
  }
  // Check if there is more than one minus sign
  if (minusCount > 1) {
    return false;  // More than one minus sign, invalid data
  }
  return true;  // Data is valid
}


float map_float(float x, float in_min, float in_max, float out_min, float out_max) {
  if (in_min == in_max) {
    SerialUSB.println("Error: El rango de entrada no puede ser cero.");
    return out_min;  // Valor de error
  }

  float result = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  // Control de saturación
  if (result > out_max) return out_max;
  if (result < out_min) return out_min;

  return result;
}


String getFormattedDateFromCompileTime() {
  String compileDate = String(__DATE__);          // Ejemplo: "Jan 07 2025"
  String day = compileDate.substring(4, 6);       // Extrae "07"
  String monthStr = compileDate.substring(0, 3);  // Extrae "Jan"
  String month = "";

  // Mapear el nombre del mes a su número correspondiente
  if (monthStr == "Jan") month = "01";
  else if (monthStr == "Feb") month = "02";
  else if (monthStr == "Mar") month = "03";
  else if (monthStr == "Apr") month = "04";
  else if (monthStr == "May") month = "05";
  else if (monthStr == "Jun") month = "06";
  else if (monthStr == "Jul") month = "07";
  else if (monthStr == "Aug") month = "08";
  else if (monthStr == "Sep") month = "09";
  else if (monthStr == "Oct") month = "10";
  else if (monthStr == "Nov") month = "11";
  else if (monthStr == "Dec") month = "12";

  // Construir la fecha en formato "DD/MM"
  return day + "/" + month;
}
String getFechaCorta(DateTime now) {
  char fechaCorta[6];  // Formato "DD/MM"
  sprintf(fechaCorta, "%02d/%02d", now.day(), now.month());
  return String(fechaCorta);
}

String getAno(DateTime now) {
  char ano[5];  // Formato "YYYY"
  sprintf(ano, "%04d", now.year());
  return String(ano);
}