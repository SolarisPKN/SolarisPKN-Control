#include "arduino_secrets.h"
#include "thingProperties.h"

#define RELAY_PIN 26
#define PULSE_NORMAL_MS 500      // Short pulse (normal power on/off)
#define PULSE_FORZADO_MS 15000   // Long pulse (forced shutdown)

bool relayActivo = false;
unsigned long relayInicio = 0;
unsigned long relayDuracion = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay OFF (active LOW)

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  Serial.println("Connecting to IoT Cloud...");
}

void loop() {
  ArduinoCloud.update();

  // Turn off relay when time is up
  if (relayActivo && (millis() - relayInicio >= relayDuracion)) {
    digitalWrite(RELAY_PIN, HIGH);
    relayActivo = false;
    Serial.println("Relay deactivated");
  }

  delay(10);
}

void onPowerPulseChange() {
  if (powerPulse) {
    Serial.println("🔘 Normal pulse (500ms)");
    activarRele(PULSE_NORMAL_MS);
    powerPulse = false;
  }
}

void onResetPulseChange() {
  if (resetPulse) {
    Serial.println("🔴 Forced pulse (15 seconds)");
    activarRele(PULSE_FORZADO_MS);
    resetPulse = false;
  }
}

void activarRele(unsigned long duracion) {
  if (relayActivo) {
    Serial.println("  ⚠️ Relay already active, ignoring");
    return;
  }
  relayActivo = true;
  relayInicio = millis();
  relayDuracion = duracion;
  digitalWrite(RELAY_PIN, LOW); // Activate relay
  Serial.printf("  Relay activated for %lu ms\n", duracion);
}