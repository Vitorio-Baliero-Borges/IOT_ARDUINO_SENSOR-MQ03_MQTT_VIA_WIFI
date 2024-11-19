# Sensor Arduino MQTT

Projeto de monitoramento de álcool e etanol com Arduino e comunicação MQTT para monitoramento remoto.

## Descrição
Este projeto utiliza o Arduino, o sensor MQ-3 e o protocolo MQTT para monitorar níveis de álcool em tempo real. Um buzzer é ativado quando a concentração de álcool ultrapassa o limite pré-definido.

## Estrutura do Projeto

- **Hardware Utilizado**:
  - Arduino Uno
  - Sensor MQ-3
  - Buzzer 5V
  - ESP8266 para comunicação Wi-Fi
  - Protoboard e jumpers
  - Fonte de alimentação 9V

- **Software**:
  - IDE Arduino para programação
  - Node-RED para monitoramento e visualização
  - MQTT como protocolo de comunicação

## Instalação e Configuração

1. **Hardware**:
   - Monte o circuito conforme o diagrama no arquivo `imagens/esquema_circuito.png`.
   - Conecte o buzzer ao pino 2 e o sensor MQ-3 ao pino A0 do Arduino.

2. **Software**:
   - Faça o upload do código fonte `sensor_arduino_mqtt.ino` para o Arduino.
   - Configure o Node-RED para exibir os dados enviados via MQTT.

3. **MQTT Broker**:
   - Certifique-se de que o broker MQTT (Mosquitto) está configurado corretamente.
   - O endereço do broker deve ser configurado no arquivo `sensor_arduino_mqtt.ino`.

4. **Node-RED Dashboard**:
   - Importe o fluxo Node-RED do arquivo `docs/node_red_flow.json` para configurar a interface.

## Resultados
- Monitoramento em tempo real dos níveis de álcool.
- Ativação do buzzer quando o nível de álcool ultrapassa 0.80.

## Estrutura do Repositório
sensor-arduino-mqtt/ ├── README.md ├── sensor_arduino_mqtt.ino ├── imagens/ │ ├── esquema_circuito.png │ ├── montagem_prototipo.jpg ├── docs/ │ ├── node_red_flow.json │ ├── artigo_cientifico.pdf
