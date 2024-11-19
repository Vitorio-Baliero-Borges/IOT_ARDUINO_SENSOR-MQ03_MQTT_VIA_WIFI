// Include Libraries
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "Arduino.h"
#include "Buzzer.h"

// Pin Definitions
#define BUZZER_PIN_SIG 2
#define MQ3_5V_PIN_AOUT A0

// Wi-Fi and MQTT Settings
const char* ssid = "Perola";          // Insira o nome da sua rede Wi-Fi
const char* password = "Tg9p.c2oh.";  // Insira a senha da sua rede Wi-Fi
const char* mqtt_server = "192.168.15.6";  // Insira o endereço IP do broker MQTT (use o IP do seu computador)
const char* mqtt_topic = "sensor/alcool";  // Tópico MQTT para o sensor de álcool

WiFiClient espClient;
PubSubClient client(espClient);

// Object initialization
Buzzer buzzer(BUZZER_PIN_SIG);

// Global variables
const float ALCOOL_THRESHOLD = 0.80; // Limiar do nível de álcool para acionar o buzzer
bool buzzerActive = false; // Variável para acompanhar o estado do buzzer

// Setup
void setup() {
    Serial.begin(9600);
    pinMode(MQ3_5V_PIN_AOUT, INPUT);
    buzzer.off();

    // Conecta ao Wi-Fi
    setup_wifi();
    
    // Configura o cliente MQTT
    client.setServer(mqtt_server, 1883);
    reconnect();
}

// Conecta ao Wi-Fi
void setup_wifi() {
    delay(10);
    Serial.println("Conectando ao WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConectado ao WiFi");
}

// Função para reconectar ao MQTT
void reconnect() {
    while (!client.connected()) {
        Serial.print("Conectando ao broker MQTT...");
        if (client.connect("ArduinoClient")) {
            Serial.println("conectado");
        } else {
            Serial.print("falhou, rc=");
            Serial.print(client.state());
            Serial.println(" tentando novamente em 5 segundos");
            delay(5000);
        }
    }
}

// Main loop
void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();

    // Leitura do sensor de álcool
    int sensorValue = analogRead(MQ3_5V_PIN_AOUT);
    float alcoolLevel = sensorValue * (5.0 / 1023.0); // Converte para nível de álcool (ajuste conforme necessário)
    Serial.print("Nível de álcool: ");
    Serial.println(alcoolLevel);

    // Publica o valor no tópico MQTT
    char payload[50];
    dtostrf(alcoolLevel, 4, 2, payload);
    client.publish(mqtt_topic, payload);

    // Ativa o buzzer se o nível de álcool estiver acima do limiar
    if (alcoolLevel >= ALCOOL_THRESHOLD) {
        if (!buzzerActive) {
            buzzer.on();
            buzzerActive = true;  // Define como ativo para evitar tocar novamente
            delay(3000); // O buzzer permanece ligado por 3 segundos
            buzzer.off();
        }
    } else {
        // Desativa o estado ativo do buzzer quando o nível de álcool está abaixo do limiar
        buzzerActive = false;
    }

    delay(2000);  // Atraso de 2 segundos entre leituras
}
