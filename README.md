# SolarisPKN-Control

🇺🇸 English | 🇦🇷 [Español](README.es.md)

## Overview

SolarisPKN-Control is a remote PC power management solution based on ESP32 and Arduino IoT Cloud.

The project allows a computer to be powered on, shut down, or forcefully powered off remotely by simulating physical presses of the motherboard's Power Switch (Power SW) button.

Unlike many similar solutions, SolarisPKN-Control does not require the Reset SW header. All actions are performed using the Power SW connector, reproducing the same behavior as pressing the physical power button on the computer case.

## Current Status

⚠️ This project is functional and under active development.

Current implementation:

* Remote power-on.
* Normal shutdown request.
* Forced shutdown.
* Arduino IoT Cloud integration.
* ESP32-based control.

Future improvements may include additional monitoring, automation, and remote management capabilities.

## Features

### Power On / Normal Shutdown

A short pulse closes the Power SW circuit for approximately 500 ms.

This simulates a standard press of the computer's power button and can be used to:

* Power on the system.
* Request a normal operating system shutdown.
* Resume compatible sleep states.

### Forced Shutdown

A long pulse closes the Power SW circuit for approximately 15 seconds.

This reproduces the behavior of holding the physical power button until the motherboard forces a shutdown.

Useful when:

* The operating system becomes unresponsive.
* Remote access is unavailable.
* The computer freezes.

## Hardware Requirements

* ESP32
* Relay module or optocoupler
* Motherboard Power SW header connection
* Power supply for ESP32

## Software Requirements

* Arduino IDE
* Arduino IoT Cloud
* ESP32 Board Package

## Technical Characteristics

* ESP32-based controller
* Cloud-managed operation
* Single-control-line design
* Low hardware complexity
* Compatible with standard PC motherboards

## Advantages

* Does not require Reset SW.
* Simple installation.
* Minimal wiring.
* Replicates real physical button behavior.
* Suitable for remote management environments.

## Real-World Use Case

SolarisPKN-Control was designed to complement a low-power remote access environment.

In my setup, I use a laptop as my primary remote access device. Through a VPN connection, I access my home network and connect to my desktop computer using Sunshine and compatible GameStream clients.

One common issue with this type of setup is that the main computer must remain powered on 24/7 to be available.

SolarisPKN-Control eliminates that requirement.

### Workflow

1. Connect to the home network through VPN.
2. Access Arduino IoT Cloud.
3. Trigger the power-on pulse.
4. ESP32 simulates a Power SW button press.
5. The computer starts normally.
6. Connect using Sunshine.
7. Shut down normally or perform a forced shutdown if required.

## Applications

* Remote gaming
* Streaming
* Homelabs
* Remote workstations
* Personal servers
* Backup systems
* Test environments

## Repository

GitHub:

https://github.com/SolarisPKN

## Author

Developed by SolarisPKN.

Part of the SolarisPKN ecosystem.

## Roadmap

### Current

* Remote power control
* Arduino IoT Cloud integration

### Planned

* Documentation improvements
* Wiring diagrams
* PCB design
* Monitoring capabilities
* Automation features

## License

License information will be defined in a future release.
