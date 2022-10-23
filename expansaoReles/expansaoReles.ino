/*
Código de exemplo para acionamento de relés conectados na interface de expansão
Aciona os 16 relés sequencialmente e sem seguida os desaciona também sequencialmente

Como ligar 16 relés na interface de expansão:
Opção 1:
* Conectar no conector de expansão um módulo de 16 relés para arquino de 5V (https://www.autocorerobotica.com.br/modulo-rele-16-canais-5v-optoacoplado)
* A conexão deve ser feita entre os pinos de mesmo nome
Opção 2:
* Conectar no conector de expansão dois módulo de 8 relés para arquino de 5V (https://www.autocorerobotica.com.br/produto/modulo-rele-8-canais-5v-optoacoplado.html)
* cada uma das duas fileiras do conector de expansão receberá o conector de um módulo de 8 relés.
* Cuidado para não inverter 5V e GND

Criado por: Prof. Bruno Raniere (https://www.instagram.com/prof_brunoraniere/)
Repositório GitHub: https://github.com/profBrunoRaniere/esp32automacao

ESP32 Automação é uma exclusividade Autocore Robótica!
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-com-lora
https://www.autocorerobotica.com.br/placa-automacao-residencial-esp32-sem-lora
*/

#include "PCF8574.h"  // PCF8574 library by Renzo Mischianti https://github.com/xreef/PCF8574_library

TwoWire I2Cone = TwoWire(0);
PCF8574 expansor1(&I2Cone, 0x20); // expansor1 endereço I2C 0x20
PCF8574 expansor2(&I2Cone, 0x24); // expansor1 endereço I2C 0x24

void expansaoWrite(uint8_t pCanal, bool pNivel);

/******************************************************/
void setup() {
  Serial.begin(115200);
  Serial.println("Teste acionamento de relés"); 

  // definição da direção dos pinos deve ser feita antes da inicialização dos PCF8574
  // expansor 1 
  for(uint8_t i=0;i<8;i++){
    expansor1.pinMode(i, OUTPUT); 
  }
  // expansor 2 
  for(uint8_t i=0;i<8;i++){
    expansor2.pinMode(i, OUTPUT);
  }

  // inicializa os PCF8574  
  if (expansor1.begin()){
    Serial.println("expansor 1 ok");  
  }
  else{
    Serial.println("expansor 1 ERRO");
  } 
  if (expansor2.begin()){
    Serial.println("expansor 2 ok");  
  }
  else{
    Serial.println("expansor 2 ERRO");
  } 
}

/******************************************************/
void loop() {
  for (uint8_t i=1; i<=16; i++){
    expansaoWrite(i, LOW);  // aciona cada relé (os relés são acionados com nível LOW)
    delay(250);
  }
  delay(1000);  // aguarda 1 segundo
  for (uint8_t i=1; i<=16; i++){
    expansaoWrite(i, HIGH);  // desaaciona cada relé (os relés são desacionados com nível HIGH)
    delay(250);
  }
  delay(1000);  // aguarda 1 segundo 
}
/******************************************************/
void expansaoWrite(uint8_t pCanal, bool pNivel){
  switch (pCanal){
    case 1:   // pino 1 conector expansão
    case 2:   // pino 3 conector expansão
    case 3:   // pino 5 conector expansão
    case 4:   // pino 7 conector expansão
    case 5:   // pino 9 conector expansão
    case 6:   // pino 11 conector expansão
    case 7:   // pino 13 conector expansão
    case 8:   // pino 15 conector expansão
      expansor1.digitalWrite((pCanal-1),pNivel);
      break;
    case 9:   // pino 2 conector expansão
    case 10:  // pino 4 conector expansão
    case 11:  // pino 6 conector expansão
    case 12:  // pino 8 conector expansão
    case 13:  // pino 10 conector expansão
    case 14:  // pino 12 conector expansão
    case 15:  // pino 14 conector expansão
    case 16:  // pino 16 conector expansão
      expansor2.digitalWrite((pCanal-9),pNivel); 
      break;    
  }
}