/*
Código de exemplo para acionamento dos relés da placa ESP32 automação.
Aciona os 4 relés sequencialmente e sem seguida os desaciona também sequencialmente

Criado por: Prof. Bruno Raniere (https://www.instagram.com/prof_brunoraniere/)
Repositório GitHub: https://github.com/profBrunoRaniere/esp32automacao

ESP32 Automação é uma exclusividade Autocore Robótica!
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-com-lora
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-sem-lora
*/

#define K1  13
#define K2  12
#define K3  27
#define K4  26

void setup() {
  Serial.begin(115200);
  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  pinMode(K3, OUTPUT);
  pinMode(K4, OUTPUT);
  Serial.println("teste de acionamento dos relés");
}

void loop() {
  // liga os 4 relés em sequencia
  digitalWrite(K1, HIGH);
  Serial.println("relé 1 acionado");
  delay(500);

  digitalWrite(K2, HIGH);
  Serial.println("relé 2 acionado");
  delay(500);

  digitalWrite(K3, HIGH);
  Serial.println("relé 3 acionado");
  delay(500);

  digitalWrite(K4, HIGH);
  Serial.println("relé 4 acionado");
  delay(1000);

  // desliga os 4 relés em sequencia
  digitalWrite(K1, LOW);
  Serial.println("relé 1 desacionado");
  delay(500);

  digitalWrite(K2, LOW);
  Serial.println("relé 2 desacionado");
  delay(500);

  digitalWrite(K3, LOW);
  Serial.println("relé 3 desacionado");
  delay(500);

  digitalWrite(K4, LOW);
  Serial.println("relé 4 desacionado");
  delay(1000);
}