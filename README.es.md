<div><p align="right">
[🇺🇸 English](README.md) | [🇪🇸 Español](README.es.md)
</p><div/>

# ⚡ SolarisPKN-Control

## 🌐 Español

🚀 **SolarisPKN-Control** es un sistema de control remoto de encendido para PC basado en ESP32 + Arduino IoT Cloud.

Permite encender, apagar o forzar el apagado de una computadora simulando el comportamiento real del botón **Power SW** de la motherboard, sin necesidad de modificar el sistema operativo ni usar software en el host.

Forma parte del ecosistema **SolarisPKN**, orientado a crear herramientas de automatización, control remoto y optimización para entornos de gaming, streaming y homelabs.

---

## 🎯 Objetivo del proyecto

El objetivo de SolarisPKN-Control es permitir el control físico remoto de una computadora de forma segura, eficiente y de bajo consumo energético, eliminando la necesidad de mantener el equipo encendido permanentemente.

---

## ✨ Características

- ⚡ Encendido remoto de PC
- 🔌 Apagado normal mediante pulsación corta
- 🛑 Apagado forzado mediante pulsación prolongada
- ☁️ Control vía Arduino IoT Cloud
- 📡 Comunicación mediante ESP32
- 🧠 Sistema optimizado para bajo consumo energético
- 🔁 Control no bloqueante del relé
- 🧩 Configuración modular y editable

---

## 🔌 Funcionamiento

El sistema simula dos tipos de interacción física:

### 🔘 Pulsación corta (500 ms)
Equivale a presionar el botón de encendido normalmente:

- Encender la PC
- Solicitar apagado del sistema operativo
- Reanudar suspensión (según BIOS/OS)

### 🔴 Pulsación larga (15 s)
Equivale a mantener presionado el botón físico:

- Apagado forzado del sistema
- Útil en cuelgues o bloqueos
- No depende del sistema operativo

---

## 🧰 Hardware requerido

- ESP32
- Módulo relé o optoacoplador
- Conexión al header **Power SW** de la motherboard
- Fuente de alimentación para el ESP32

---

## ☁️ Software requerido

- Arduino IDE
- Arduino IoT Cloud
- Soporte ESP32 en Arduino

---

## ⚡ Optimizaciones de energía

Este firmware incluye optimizaciones diseñadas para reducir consumo energético y temperatura de operación durante uso continuo.

### 🔧 Cambios implementados

- CPU reducida de 240 MHz → 80 MHz
- Bluetooth deshabilitado
- WiFi en modo ahorro (MAX_MODEM)
- Light Sleep habilitado
- Control de relé no bloqueante

---

## 📊 Estimaciones de mejora (basado en pruebas personales)

> ⚠️ Estas métricas son estimaciones obtenidas durante pruebas personales con mi configuración de hardware.  
> Los resultados pueden variar según el modelo de ESP32, módulo de relé, fuente de alimentación, calidad de señal Wi-Fi, temperatura ambiente y carga del sistema.

| Métrica | Versión anterior | Versión optimizada | Mejora estimada |
|--------|------------------|--------------------|------------------|
| Frecuencia CPU | 240 MHz | 80 MHz | ↓ ~66% |
| Bluetooth | Activo | Desactivado | ↓ consumo innecesario |
| WiFi | Default | MAX_MODEM | ↓ consumo en reposo |
| Modo Sleep | Desactivado | Light Sleep | ↓ consumo idle |
| Consumo en reposo | 100% | 70–80% | ↓ ~20–30% |
| Temperatura operativa | Normal | Más baja | ↓ ~3–8°C (estimado) |

---

## 🌡️ Impacto en temperatura y durabilidad

La reducción de frecuencia de CPU y la activación de modos de ahorro energético reduce el estrés térmico del sistema.

> 💡 En base a pruebas personales, una menor temperatura de operación puede contribuir a una mayor estabilidad en funcionamiento 24/7 y potencialmente extender la vida útil de los componentes electrónicos.

⚠️ No se trata de una mejora garantizada ni certificada, ya que depende de factores ambientales y de hardware.

---

## 🧠 Casos de uso

- 🎮 Gaming remoto
- 📺 Streaming 24/7
- 🏠 Homelabs
- 🖥️ Estaciones de trabajo remotas
- 🔧 Servidores personales
- 🧪 Entornos de testing
- 🌐 Acceso remoto con VPN + Sunshine / Moonlight

---

## 🔁 Flujo de uso

1. Conexión a red mediante VPN
2. Acceso a Arduino IoT Cloud
3. Activación de pulso de encendido
4. ESP32 activa relé (Power SW)
5. La PC inicia normalmente
6. Acceso remoto mediante Sunshine / GameStream
7. Apagado normal o forzado según necesidad

---

## 🗺️ Roadmap

### v1.x
- Control remoto básico (implementado)
- Integración con Arduino IoT Cloud
- Optimización energética (implementada)
- Documentación mejorada

### v2.0 (en desarrollo conceptual)
- 📡 Wake-on-LAN híbrido
- 📊 Monitor de estado de PC
- 🔔 Notificaciones de estado
- 🌐 API local opcional
- 🧠 Automatización avanzada

---

## ❤️ Ecosistema SolarisPKN

Este proyecto forma parte de:

- 🧪 SolarisPKN-Labs
- 🛠️ SolarisPKN-LiveTools
- ⚙️ SolarisPKN-Control

Un ecosistema enfocado en automatización, control remoto y herramientas para creadores de contenido y entornos técnicos.

---

## 📜 Licencia

MIT License

Libre para usar, modificar y compartir.