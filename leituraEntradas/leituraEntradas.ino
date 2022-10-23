/*
Código de exemplo para leitura das entradas optoacopladas da placa ESP32 automação.
Lê as entradas em envia o status via serial.

Criado por: Prof. Bruno Raniere (https://www.instagram.com/prof_brunoraniere/)
Repositório GitHub: https://github.com/profBrunoRaniere/esp32automacao

ESP32 Automação é uma exclusividade Autocore Robótica!
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-com-lora
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-sem-lora
*/

#define I1  35
#define I2  34
#define I3  39
#define I4  36

void setup() {
  Serial.begin(115200);
  pinMode(I1, INPUT);
  pinMode(I2, INPUT);
  pinMode(I3, INPUT);
  pinMode(I4, INPUT);
  Serial.println("teste das entradas optoacopladas");
}

void loop() {
  if(digitalRead(I1) == 0){
    Serial.println("Entrada I1 ON");  // pino low = ativado (lógica invertida)  
  }
  else{
    Serial.println("Entrada I1 OFF");  // pino high = desativado (lógica invertida)  
  }

  if(digitalRead(I2) == 0){
    Serial.println("Entrada I2 ON");  // pino low = ativado (lógica invertida)  
  }
  else{
    Serial.println("Entrada I2 OFF");  // pino high = desativado (lógica invertida)  
  }

  if(digitalRead(I3) == 0){
    Serial.println("Entrada I3 ON");  // pino low = ativado (lógica invertida)  
  }
  else{
    Serial.println("Entrada I3 OFF");  // pino high = desativado (lógica invertida)  
  }

  if(digitalRead(I4) == 0){
    Serial.println("Entrada I4 ON");  // pino low = ativado (lógica invertida)  
  }
  else{
    Serial.println("Entrada I4 OFF");  // pino high = desativado (lógica invertida)  
  }

  Serial.println("");
  delay(1000);
}