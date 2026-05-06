#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char* ssid = "FIAP-IOT";
const char* password = "F!@p25.IOT";

// MQTT (HiveMQ Cloud)
const char* mqtt_server = "51bf02160f1f4ecb81b48d440bf18c96.s1.eu.hivemq.cloud";
const int mqtt_port = 1883;
const char* mqtt_user = "rm566516";
const char* mqtt_pass = "Fiap210806";

// Tópicos
const char* topicoPot = "potenciometro/valor1";
const char* topicoDist = "ultrassonico/valor1";

// Pinos
#define POT_PIN 12
#define TRIG_PIN 0
#define ECHO_PIN 2

WiFiClient espClient;
PubSubClient client(espClient);

// =====================
// Conectar WiFi
// =====================
void setup_wifi() {
  Serial.print("Conectando ao WiFi...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi conectado!");
}

// =====================
// Conectar MQTT
// =====================
void reconnect() {
  while (!client.connected()) {
    Serial.print("Conectando ao MQTT...");

    if (client.connect("ESP32Client", mqtt_user, mqtt_pass)) {
      Serial.println("Conectado!");
    } else {
      Serial.print("Erro: ");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 2s...");
      delay(2000);
    }
  }
}

// =====================
// Ler HC-SR04
// =====================
float lerDistancia() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracao = pulseIn(ECHO_PIN, HIGH);

  float distancia = duracao * 0.034 / 2;
  return distancia;
}

// =====================
// Setup
// =====================
void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_port);
}

// =====================
// Loop principal
// =====================
void loop() {

  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  // Leitura potenciômetro
  int valorPot = analogRead(POT_PIN);

  // Leitura distância
  float distancia = lerDistancia();

  // Converter para string
  char potString[10];
  char distString[10];

  sprintf(potString, "%d", valorPot);
  sprintf(distString, "%.2f", distancia);

  // Publicar MQTT
  client.publish(topicoPot, potString);
  client.publish(topicoDist, distString);

  // Debug
  Serial.print("Potenciometro: ");
  Serial.print(valorPot);
  Serial.print(" | Distancia: ");
  Serial.println(distancia);

  delay(1000); // 1 segundo
}