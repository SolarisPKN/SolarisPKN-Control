<p align="right">
[🇺🇸 English](README.md) | [🇪🇸 Español](README.es.md
</p>

# ⚡ SolarisPKN-Control

## 🌐 English

🚀 **SolarisPKN-Control** is a remote PC power control system based on ESP32 + Arduino IoT Cloud.

It allows you to turn on, shut down, or force shutdown a computer by simulating the real behavior of the motherboard **Power SW button**, without requiring any software installed on the host system.

This project is part of the **SolarisPKN ecosystem**, focused on building automation, remote control, and infrastructure tools for gaming, streaming, and homelab environments.

---

## 🎯 Project Goal

The goal of SolarisPKN-Control is to enable safe, efficient, and low-power remote physical control of a PC, eliminating the need to keep the system running 24/7.

---

## ✨ Features

- ⚡ Remote PC power-on
- 🔌 Normal shutdown via short pulse
- 🛑 Forced shutdown via long press simulation
- ☁️ Arduino IoT Cloud integration
- 📡 ESP32-based control system
- 🧠 Low-power optimized firmware
- 🔁 Non-blocking relay state machine
- 🧩 Modular and configurable architecture

---

## 🔌 How it works

The system simulates two physical button behaviors:

### 🔘 Short pulse (500ms)
Equivalent to a normal press of the power button:

- Turn on the PC
- Request OS shutdown
- Resume from sleep (depending on BIOS/OS settings)

### 🔴 Long pulse (15s)
Equivalent to holding the physical button:

- Forces system shutdown
- Used for system freezes or unresponsive states
- Independent from operating system

---

## 🧰 Hardware Requirements

- ESP32 development board
- Relay module or optocoupler
- Connection to motherboard **Power SW header**
- Power supply for ESP32

---

## ☁️ Software Requirements

- Arduino IDE
- Arduino IoT Cloud
- ESP32 board package for Arduino

---

## ⚡ Power Optimizations

This firmware includes energy-saving optimizations designed to reduce power consumption and operating temperature during continuous operation.

### 🔧 Implemented optimizations

- CPU frequency reduced: 240 MHz → 80 MHz
- Bluetooth disabled
- WiFi power saving mode enabled (MAX_MODEM)
- Light Sleep enabled
- Non-blocking relay control system

---

## 📊 Estimated Improvements (based on personal testing)

> ⚠️ These values are approximate estimations based on personal testing with my own hardware setup.  
> Actual results may vary depending on ESP32 model, relay module, power supply quality, Wi-Fi signal strength, ambient temperature, and system workload.

| Metric | Previous Version | Optimized Version | Estimated Improvement |
|--------|------------------|------------------|----------------------|
| CPU Frequency | 240 MHz | 80 MHz | ↓ ~66% |
| Bluetooth | Enabled | Disabled | Reduced unnecessary load |
| WiFi Mode | Default | MAX_MODEM | Lower idle power usage |
| Sleep Mode | Disabled | Light Sleep | Reduced idle consumption |
| Idle Power Consumption | 100% | 70–80% | ↓ ~20–30% |
| Operating Temperature | Normal | Cooler | ↓ ~3–8°C (estimated) |

---

## 🌡️ Thermal Impact & Reliability

Reducing CPU frequency and enabling power-saving modes lowers system thermal stress.

> 💡 Based on personal testing, lower operating temperatures may improve long-term stability during 24/7 operation and potentially contribute to extended component lifespan.

⚠️ This is not a guaranteed or certified improvement, as real-world results depend on environmental and hardware conditions.

---

## 🧠 Use Cases

- 🎮 Remote gaming setups
- 📺 24/7 streaming systems
- 🏠 Homelab infrastructure
- 🖥️ Remote workstations
- 🔧 Personal servers
- 🧪 Testing environments
- 🌐 VPN + Sunshine / Moonlight remote access setups

---

## 🔁 Workflow

1. Connect via VPN to home network
2. Access Arduino IoT Cloud dashboard
3. Trigger power-on pulse
4. ESP32 activates relay (Power SW simulation)
5. PC boots normally
6. Connect via Sunshine / GameStream
7. Shutdown normally or force shutdown if needed

---

## 🗺️ Roadmap

### v1.x
- Basic remote power control (implemented)
- Arduino IoT Cloud integration
- Power optimization system (implemented)
- Improved documentation

### v2.0 (concept stage)
- 📡 Hybrid Wake-on-LAN support
- 📊 PC status monitoring
- 🔔 Notification system
- 🌐 Optional local API
- 🧠 Advanced automation layer

---

## ❤️ SolarisPKN Ecosystem

This project is part of:

- 🧪 SolarisPKN-Labs
- 🛠️ SolarisPKN-LiveTools
- ⚙️ SolarisPKN-Control

An ecosystem focused on automation, remote control systems, and tools for creators and technical environments.

---

## 📜 License

MIT License

Free to use, modify, and distribute.