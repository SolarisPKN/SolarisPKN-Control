#include "arduino_secrets.h"
#include "thingProperties.h"

#define RELAY_PIN 26
#define PULSE_NORMAL_MS 500      // Pulso corto (encender/apagar normal)
#define PULSE_FORZADO_MS 15000   // Pulso largo (apagado forzoso)

bool relayActivo = false;
unsigned long relayInicio = 0;
unsigned long relayDuracion = 0;

void setup() {
  Serial.begin(115200);
  delay(1500);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relé apagado (activo LOW)

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  Serial.println("Conectando a IoT Cloud...");
}

void loop() {
  ArduinoCloud.update();

  // Apagar relé cuando se cumpla el tiempo
  if (relayActivo && (millis() - relayInicio >= relayDuracion)) {
    digitalWrite(RELAY_PIN, HIGH);
    relayActivo = false;
    Serial.println("Relé desactivado");
  }

  delay(10);
}

void onPowerPulseChange() {
  if (powerPulse) {
    Serial.println("🔘 Pulso normal (500ms)");
    activarRele(PULSE_NORMAL_MS);
    powerPulse = false;
  }
}

void onResetPulseChange() {
  if (resetPulse) {
    Serial.println("🔴 Pulso forzado (15 segundos)");
    activarRele(PULSE_FORZADO_MS);
    resetPulse = false;
  }
}

void activarRele(unsigned long duracion) {
  if (relayActivo) {
    Serial.println("  ⚠️ Relé ya activo, ignorando");
    return;
  }
  relayActivo = true;
  relayInicio = millis();
  relayDuracion = duracion;
  digitalWrite(RELAY_PIN, LOW); // Activar relé
  Serial.printf("  Relé activado por %lu ms\n", duracion);
}