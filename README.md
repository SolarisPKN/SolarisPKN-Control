# Solaris PKN Control

Control remoto para PC basado en ESP32 y Arduino IoT Cloud.

## ¿Qué hace?

Solaris PKN Control permite controlar una computadora de forma remota utilizando un ESP32 conectado al conector Power SW de la motherboard.

A diferencia de otros proyectos similares, no requiere utilizar el conector Reset SW. Todo el control se realiza simulando las mismas acciones que haría un usuario al presionar físicamente el botón de encendido del gabinete.

## Funciones

### Encendido y apagado normal

Cuando se activa un pulso corto, el ESP32 cierra momentáneamente el circuito Power SW durante aproximadamente 500 ms.

Este comportamiento equivale a presionar brevemente el botón de encendido del gabinete.

Dependiendo del estado actual del sistema operativo, esto permite:

* Encender la PC.
* Solicitar un apagado normal.
* Reanudar desde estados compatibles.

### Apagado forzado

Cuando se activa un pulso largo, el ESP32 mantiene cerrado el circuito Power SW durante aproximadamente 15 segundos.

Este comportamiento equivale a mantener presionado el botón de encendido del gabinete hasta que la motherboard fuerce el apagado del equipo.

Esta función resulta útil cuando:

* El sistema operativo se bloquea.
* No existe acceso remoto.
* La PC deja de responder.

### Estado de la PC

El sistema utiliza una línea de feedback conectada al ESP32 para detectar si la computadora se encuentra encendida o apagada.

La información se muestra en Arduino IoT Cloud y permite conocer el estado real del equipo.

## Características técnicas

* ESP32
* Arduino IoT Cloud
* Actualizaciones OTA
* Detección de estado de la PC
* Debounce para evitar falsas detecciones
* Optimización energética del ESP32
* Compatible con asistentes de voz mediante automatizaciones de Arduino Cloud

## Hardware requerido

* ESP32
* 1 relé o módulo optoacoplado
* Conexión al header Power SW de la motherboard
* Fuente de alimentación para el ESP32

## Ventajas

* No utiliza el conector Reset SW.
* Solo requiere una salida de control.
* Instalación sencilla.
* Menor cantidad de cableado.
* Comportamiento idéntico al botón físico del gabinete.

## Autor

Desarrollado por PabloKoutaNya.

Proyecto perteneciente al ecosistema Solaris PKN Control.
