
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida
 
//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
Serial.begin(9600); // inicializa a comunicação serial

 //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  
}
 
//Função que será executada continuamente
void loop() {
  //Limpa a tela
  lcd.clear();
   //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  lcd.print("Temperatura: ");
  lcd.setCursor(3, 1);
  
temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
Serial.print("Temperatura: ");
Serial.println(temperatura);
  lcd.print(temperatura);
delay(2000);
}
