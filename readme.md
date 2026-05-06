# 📡 Monitoramento Inteligente com IoT (ESP32 + MQTT + Node-RED)

Nomes: Johnny Dias & João Adão
RMs: 566516 & 563409

## 📖 Descrição do Projeto
Este projeto tem como objetivo implementar uma solução de **monitoramento em tempo real utilizando Internet das Coisas (IoT)**.

A proposta consiste em simular o monitoramento de uma máquina utilizando:
- Um **potenciômetro** (simulando sensor analógico)
- Um **sensor ultrassônico HC-SR04** (simulando entrada digital de distância)

Os dados coletados pelo ESP32 são enviados via protocolo **MQTT** para um broker na nuvem e, posteriormente, processados pelo **Node-RED**, onde são:
- Exibidos em um dashboard em tempo real
- Armazenados em um banco de dados MySQL
- Integrados com uma API externa (ViaCEP)

---

## 🏗️ Arquitetura da Solução

A arquitetura do sistema segue o fluxo abaixo:

Sensores → ESP32 → MQTT (HiveMQ Cloud) → Node-RED → Dashboard + Banco de Dados + API Externa


### 🔹 Componentes

**1. ESP32**
- Realiza a leitura dos sensores:
  - Potenciômetro (GPIO 12)
  - Ultrassônico HC-SR04 (TRIG: GPIO 0 | ECHO: GPIO 2)
- Envia os dados via MQTT nos tópicos:
  - `potenciometro/valor1`
  - `ultrassonico/valor1`

**2. Broker MQTT (HiveMQ Cloud)**
- Responsável por intermediar a comunicação entre ESP32 e Node-RED
- Comunicação segura via TLS (porta 8883)

**3. Node-RED**
Responsável por:
- Receber dados via MQTT
- Processar e transformar os dados
- Inserir no banco MySQL
- Exibir no dashboard
- Consumir API externa

**4. Banco de Dados (MySQL)**
- Armazena os dados dos sensores na tabela `LEITURAS`

**5. API Externa (ViaCEP)**
- Consulta dados de endereço a partir de um CEP
- Exibida no dashboard via botão

---

## 🛠️ Tecnologias Utilizadas

- **ESP32** (microcontrolador)
- **Arduino IDE** (programação embarcada)
- **MQTT** (protocolo de comunicação IoT)
- **HiveMQ Cloud** (broker MQTT)
- **Node-RED** (orquestração e integração)
- **Node-RED Dashboard** (visualização)
- **MySQL** (persistência de dados)
- **API ViaCEP** (integração externa)
- **JavaScript (Function Node)** (processamento no Node-RED)

---

## ▶️ Instruções de Execução

### 🔹 1. Configuração do ESP32
1. Conecte os sensores:
   - Potenciômetro:
     - SIG → GPIO 12
     - VCC → 5V
     - GND → GND
   - Ultrassônico HC-SR04:
     - TRIG → GPIO 0
     - ECHO → GPIO 2
     - VCC → 5V
     - GND → GND

2. Configure no código:
   - Wi-Fi (SSID e senha)
   - Credenciais do MQTT (HiveMQ)

3. Faça o upload do código via Arduino IDE.

---

### 🔹 2. Configuração do Node-RED
1. Importe o fluxo JSON fornecido no Node-RED
2. Configure o broker MQTT:
   - Host: `51bf02160f1f4ecb81b48d440bf18c96.s1.eu.hivemq.cloud`
   - Porta: `8883`
   - TLS ativado
   - Usuário e senha configurados

3. Ajuste o tópico MQTT (se necessário)

---

### 🔹 3. Banco de Dados (MySQL)

Crie a tabela:

```sql
CREATE TABLE LEITURAS (
    id INT AUTO_INCREMENT PRIMARY KEY,
    potenciometro VARCHAR(10),
    ultrassonico VARCHAR(10),
    data DATETIME
);
