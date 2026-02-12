# BioDiges V0.8.7 - Sistema de Monitoreo de Biodigestor

## Descripción
Este repositorio contiene el firmware para una unidad de monitoreo de biodigestor basada en la placa SAMD21. El sistema está diseñado para registrar variables críticas del proceso de biodigestión, asegurando un seguimiento preciso y almacenamiento de datos para análisis posterior.

El sistema monitorea y registra:
*   **Temperatura**: Ambiental y del líquido (hasta 3 sensores DS18B20).
*   **pH**: Acidez/alcalinidad del sustrato (hasta 3 sensores).
*   **Conductividad Eléctrica (EC)**: Hasta 3 sensores.
*   **Humedad Relativa**: Mediante sensor DHT22.

Los datos se visualizan localmente en una pantalla OLED SSD1306 y se almacenan en una tarjeta SD en formato CSV. Además, cuenta con un Reloj de Tiempo Real (RTC) DS3231 para el sellado de tiempo preciso de los registros.

## Hardware Requerido
*   **Microcontrolador**: Placa basada en SAMD21 (compatible con Arduino Zero/M0).
*   **Sensores de Temperatura**: DS18B20 (x3).
*   **Sensor Ambiental**: DHT22 (Temperatura y Humedad).
*   **Módulos de pH**: Interfaces analógicas de pH (x3).
*   **Módulos de EC**: Interfaces analógicas de Conductividad Eléctrica (x3).
*   **Almacenamiento**: Módulo de tarjeta SD (SPI).
*   **Reloj**: RTC DS3231 (I2C).
*   **Visualización**: Pantalla OLED SSD1306 (I2C).
*   **Indicadores**: LED NeoPixel (integrado o externo).
*   **Interfaz de Usuario**: Botones pulsadores para navegación y control.

## Librerías Dependientes
El código depende de las siguientes librerías de Arduino:
*   `OneWire`
*   `DallasTemperature`
*   `DHT sensor library`
*   `Adafruit_NeoPixel`
*   `OneButton`
*   `RTClib`
*   `U8g2`
*   `SPI`
*   `SD`

## Implementación
Aquí se muestra el prototipo de la unidad de monitoreo:

![Prototipo del Sistema](img/prototype.jpg)

*(Nota: Para visualizar la imagen, crea una carpeta llamada `img` en este directorio y añade una foto nombrada `prototype.jpg`)*

## Autor
**Alejandro Rebolledo**

## Licencia
Este proyecto está licenciado bajo la **Licencia Creative Commons Atribución 4.0 Internacional (CC BY 4.0)**.
Puedes ver el texto completo de la licencia en el archivo [LICENSE](LICENSE).

## Descargo de Responsabilidad (Disclaimer)
ESTE SOFTWARE Y LA DOCUMENTACIÓN ESTÁN PROPORCIONADOS "TAL CUAL", SIN GARANTÍA DE NINGÚN TIPO, EXPRESA O IMPLÍCITA, INCLUYENDO PERO NO LIMITADO A LAS GARANTÍAS DE COMERCIABILIDAD, IDONEIDAD PARA UN PROPÓSITO PARTICULAR Y NO INFRACCIÓN. EN NINGÚN CASO EL AUTOR O LOS TITULARES DE LOS DERECHOS DE AUTOR SERÁN RESPONSABLES DE NINGUNA RECLAMACIÓN, DAÑOS U OTRA RESPONSABILIDAD, YA SEA EN UNA ACCIÓN DE CONTRATO, AGRAVIO O DE OTRO TIPO, QUE SURJA DE, FUERA DE O EN CONEXIÓN CON EL SOFTWARE O EL USO U OTROS TRATOS EN EL SOFTWARE.

EL USO DE ESTE SISTEMA DE MONITOREO ES BAJO SU PROPIO RIESGO. EL AUTOR NO SE HACE RESPONSABLE POR DAÑOS EN EL HARDWARE, PÉRDIDA DE DATOS O CUALQUIER OTRO PERJUICIO OCASIONADO POR EL USO DE ESTE FIRMWARE.
