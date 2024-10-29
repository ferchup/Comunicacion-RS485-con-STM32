# Comunicación RS485 entre dos STM32
El objetivo es crear unas experiencias para implementar la comunicación STM32F3 utilizando la interfaz RS485. 
La comunicación se deberá realizar utilizando los periféricos UART y GPIO. Al final de las experiencias, dos STM32F3 deberán comunicarse bidireccionalmente, transmitiendo y recibiendo datos de forma confiable a través de RS485. 
También, se definirá una pequeña aplicación simulando un sistema de envío y recepción de datos que podría ser usado en la vida real. 
## Materiales necesarios
- Dos placas STM32F303ZE
- Módulos convertidores RS485 a UART (en este caso RS485 CAN Shield de Waveshare electronics)
## Experiencias
El proyecto estará dividido en diferentes experiencias incrementales.
### Experiencia 1: Introducción a STM32 y UART
**Objetivo:** Aprender a configurar y utilizar el periférico UART en el STM32F3.
   - Paso 1: Introducción al entorno STM32CubeIDE para generar código HAL.
   - Paso 2: Configuración de los pines TX y RX y parámetros del UART en STM32CubeIDe.
   - Paso 3: Generar el código inicial en STM32CubeIDE y cargar un código básico que envíe y reciba datos en una terminal serie usando UART.

**Práctica:** Realizar un bucle de eco donde los datos recibidos por UART se reenvíen a la terminal, todo en el mismo dispositivo.

### Experiencia 2: Introducción a RS485
**Objetivo:** Enseñar el funcionamiento de la interfaz RS485 y cómo conectar los módulos RS485 a STM32F303 y configurar la comunicación serial RS485 en modo half-duplex entre dos placas STM32.
   - Paso 1: Conectar físicamente los módulos MAX485 a las placas STM32F3, teniendo en cuenta la topología de conexiones TX, RX, 485_E.
   - Paso 2: Configurar el pin para controlar la señal de habilitación (485_E) del módulo RS485 CAN Shield desde el STM32F303, fichero .ioc.
   - Paso 3: En el archivo .ioc, configurar la UART en modo half-duplex.
   - Paso 4: Crear una función para controlar el envío y recepción de datos (habilitar 485_E para transmisión y deshabilitarlo para recepción).
   - Paso 5: Programar una comunicación básica donde una placa envíe un mensaje y la otra lo reciba.
**Práctica:** Enviar y recibir mensajes de una STM32 a la otra, por muestreo.

### Experiencia 3: Comunicación entre dos STM32 usando RS485 mediante interrupciones
**Objetivo:** Mejorar la comunicación entre dos placas STM32 para realizar la transmisión de información usando RS485 e interrupciones.
   - Paso 1: En el archivo .ioc, configurar la UART en modo half-duplex.
   - Paso 2: Habilitar interrupciones de UART para mejorar la eficiencia de comunicación.
   - Paso 3: Crear formato de paquete adecuado para la transmisión de información
   - Adecuación del código de la experiencia anterior para la transmisión mediante interrupciones

**Práctica:** Realizar un intercambio de datos donde se envíen datos desde una STM32 a otra garantizando la llegada del mensaje, haciendo uso de las interrupciones.

### Experiencia 4: Mejora de comunicación entre dos STM32 usando RS485
**Objetivo:** Mejorar la comunicación entre dos STM32 usando RS485 garantizando la integridad de los datos.
   - Paso 1: Aplicar protocolos de control de errores como CRC y ACK.
   - Paso 2: Implementar temporización y retransmisión en caso de fallo.
   - Paso 3: Crear formato de paquete propio y adecuado para la transmisión

**Práctica:** Realizar una comunicación bidireccional con verificación de recepción (ACK) entre STM32 utilizando RS485 y CRC para verificar la integridad del mensaje.

## Práctica final
**Objetivo:** Crear una aplicación más compleja utilizando la comunicación RS485.
   - Paso 1: Explicar cómo se pueden interconectar múltiples dispositivos en un bus RS485 (modo maestro / esclavo).
   - Paso 2: Crear un formato de paquetes propio con un ID para que cada STM32 funcione en modo maestro/esclavo, pudiendo enviar comandos o datos desde cada dispositivo.

**Práctica:** Crear una pequeña red con 2 STM32, donde un dispositivo funcione como maestro y el otro como esclavo.
Se deberá realizar, la petición del maestro al esclavo indicando este tipo de mensaje encendiendo una LED y respondiendo al maestro mediante un paquete de tipo ACK.
Cuando el maestro pulse un botón este realizará una emisión broadcast que se deberá indicar encendiendo otra LED cuando se reciba el mensaje pero no se tendrá que responder al maestro en este caso. 
