# SolarisPKN-Control

🇦🇷 Español | 🇺🇸 [English](README.md)

## Descripción General

SolarisPKN-Control es una solución de control remoto de encendido para computadoras basada en ESP32 y Arduino IoT Cloud.

El proyecto permite encender, apagar o forzar el apagado de una computadora simulando pulsaciones físicas sobre el conector Power SW de la motherboard.

A diferencia de muchas soluciones similares, SolarisPKN-Control no requiere utilizar el conector Reset SW. Todas las acciones se realizan utilizando únicamente el conector Power SW, reproduciendo exactamente el comportamiento del botón físico del gabinete.

## Estado Actual

⚠️ Este proyecto es funcional y se encuentra en desarrollo activo.

Implementación actual:

* Encendido remoto.
* Solicitud de apagado normal.
* Apagado forzado.
* Integración con Arduino IoT Cloud.
* Control mediante ESP32.

Futuras versiones podrán incorporar funciones adicionales de monitoreo, automatización y administración remota.

## Características

### Encendido y Apagado Normal

Un pulso corto cierra el circuito Power SW durante aproximadamente 500 ms.

Este comportamiento equivale a presionar brevemente el botón de encendido del gabinete y permite:

* Encender la computadora.
* Solicitar un apagado normal del sistema operativo.
* Reanudar estados de suspensión compatibles.

### Apagado Forzado

Un pulso largo mantiene cerrado el circuito Power SW durante aproximadamente 15 segundos.

Este comportamiento equivale a mantener presionado el botón físico hasta que la motherboard fuerce el apagado del equipo.

Resulta útil cuando:

* El sistema operativo deja de responder.
* No existe acceso remoto disponible.
* La computadora se bloquea.

## Hardware Requerido

* ESP32
* Módulo relé u optoacoplador
* Conexión al header Power SW de la motherboard
* Fuente de alimentación para el ESP32

## Software Requerido

* Arduino IDE
* Arduino IoT Cloud
* Paquete de placas ESP32

## Características Técnicas

* Controlador basado en ESP32
* Operación gestionada desde la nube
* Diseño de una sola línea de control
* Baja complejidad de hardware
* Compatible con motherboards estándar

## Ventajas

* No requiere utilizar Reset SW.
* Instalación sencilla.
* Menor cantidad de cableado.
* Comportamiento idéntico al botón físico.
* Ideal para administración remota.

## Caso de Uso Real

SolarisPKN-Control fue diseñado para complementar un entorno de acceso remoto de bajo consumo energético.

En mi caso utilizo una notebook como dispositivo principal de acceso remoto. Mediante una conexión VPN accedo a mi red doméstica y me conecto a mi computadora de escritorio utilizando Sunshine y clientes compatibles con GameStream.

Uno de los problemas habituales de este tipo de configuraciones es que la computadora principal debe permanecer encendida las 24 horas para estar disponible.

SolarisPKN-Control elimina esa necesidad.

### Flujo de Trabajo

1. Conectarse a la red doméstica mediante VPN.
2. Acceder a Arduino IoT Cloud.
3. Activar el pulso de encendido.
4. El ESP32 simula una pulsación del botón Power.
5. La computadora inicia normalmente.
6. Conectarse mediante Sunshine.
7. Apagar normalmente o forzar el apagado si es necesario.

## Aplicaciones

* Gaming remoto
* Streaming
* Homelabs
* Estaciones de trabajo remotas
* Servidores personales
* Equipos de respaldo
* Entornos de pruebas

## Repositorio

GitHub:

https://github.com/SolarisPKN

## Autor

Desarrollado por SolarisPKN.

Proyecto perteneciente al ecosistema SolarisPKN.

## Hoja de Ruta

### Actual

* Control remoto de energía
* Integración con Arduino IoT Cloud

### Planificado

* Mejoras de documentación
* Diagramas de conexión
* Diseño PCB
* Capacidades de monitoreo
* Funciones de automatización

## Licencia

La licencia del proyecto será definida en futuras versiones.
