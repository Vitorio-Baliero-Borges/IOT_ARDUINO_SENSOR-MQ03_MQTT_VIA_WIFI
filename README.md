# Sensor Arduino MQTT

Projeto de monitoramento de álcool e etanol com Arduino e comunicação MQTT para monitoramento remoto.

---

## 📖 Descrição

Este projeto utiliza o Arduino, o sensor MQ-3 e o protocolo MQTT para monitorar níveis de álcool em tempo real. Um buzzer é ativado quando a concentração de álcool ultrapassa o limite pré-definido.

---

## 🛠️ Estrutura do Projeto

### Hardware Utilizado:
- **Arduino Uno**
- **Sensor MQ-3**
- **Buzzer 5V**
- **ESP8266** para comunicação Wi-Fi
- **Protoboard e Jumpers**
- **Fonte de Alimentação 9V**

### Software:
- **IDE Arduino** para programação
- **Node-RED** para monitoramento e visualização
- **MQTT** como protocolo de comunicação

---

## 📋 Configuração do Projeto

1. Clone este repositório:
    ```bash
    git clone https://github.com/SEU_USUARIO/sensor-arduino-mqtt.git
    ```

2. Abra o código `sensor_arduino_mqtt.ino` na IDE do Arduino.

3. Configure os parâmetros de Wi-Fi e MQTT no código:
    ```cpp
    const char* ssid = "SEU_SSID";
    const char* password = "SUA_SENHA";
    const char* mqtt_server = "IP_DO_BROKER";
    ```

4. Carregue o código na placa Arduino.

5. Importe o fluxo `node_red_flow.json` para o Node-RED.

6. Certifique-se de que o broker MQTT esteja em execução.

---

## ⚙️ Instalação e Configuração

### Hardware:
1. Monte o circuito conforme o diagrama no arquivo `imagens/esquema_circuito.png`.
2. Conecte o buzzer ao pino 2 e o sensor MQ-3 ao pino A0 do Arduino.

### Software:
1. Faça o upload do código fonte `sensor_arduino_mqtt.ino` para o Arduino.
2. Configure o Node-RED para exibir os dados enviados via MQTT.

### MQTT Broker:
1. Certifique-se de que o broker MQTT (Mosquitto) está configurado corretamente.
2. O endereço do broker deve ser configurado no arquivo `sensor_arduino_mqtt.ino`.

### Node-RED Dashboard:
1. Importe o fluxo Node-RED do arquivo `docs/node_red_flow.json` para configurar a interface.

---

## 🎥 Vídeo de Demonstração

Confira o vídeo de demonstração do projeto em funcionamento no YouTube:
[**Demonstração Sensor Arduino MQTT**](https://www.youtube.com/watch?v=SEU_VIDEO_LINK)

---

## 📊 Resultados

- Monitoramento em tempo real dos níveis de álcool.
- Ativação do buzzer quando o nível de álcool ultrapassa 0.80.

---

## 📂 Estrutura do Repositório

```plaintext
sensor-arduino-mqtt/
├── README.md
├── sensor_arduino_mqtt.ino
├── imagens/
│   ├── esquema_circuito.png
│   ├── montagem_prototipo.jpg
├── docs/
│   ├── node_red_flow.json
│   ├── artigo_cientifico.pdf
