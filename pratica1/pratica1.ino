//https://www.filipeflop.com/blog/controlando-um-lcd-16x2-com-arduino/
//https://www.arduino.cc/en/Tutorial/Button  
#include <LiquidCrystal.h>

/*
   Tarefas: 
   Medir temperatura (LM35)
   Display LCD(16x2)
       mostrar temp.
       relogio

   botão p/ ajuste do relogio
*/
int segundos = 0, minutos = 38, horas = 18;

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida
int buttonState = 0;
const int buttonPin = 0; // botão de ajuste do relogio
//Função que será executada uma vez quando ligar ou resetar o Arduino
void setup() {
  Serial.begin(9600); // inicializa a comunicação serial
  //define como entrada o pino 
  pinMode(buttonPin, INPUT);
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);

}
void conta()
{
  if (segundos < 59)segundos++;
  else if (minutos < 59) {
    minutos++;
    segundos = 0;
  }
  else if (horas < 24) {
    horas++;
    minutos = 0;
    segundos = 0;
  }
  else {
    segundos = 0;
    minutos = 0;
    horas = 0;
  }


}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == LOW) {
    if (minutos < 59)
      minutos++;
    else {
      horas++;
      minutos = 0;
    }
  }
  //Limpa a tela
  lcd.clear();
  //Posiciona o cursor na coluna 3, linha 0;
  lcd.setCursor(3, 0);
  //Envia o texto entre aspas para o LCD
  if ( horas < 10)
    lcd.print("0");
  lcd.print(horas);
  lcd.print(":");
  if ( minutos < 10)
    lcd.print("0");
  lcd.print(minutos);
  lcd.print(":");
  if ( segundos < 10)
    lcd.print("0");
  lcd.print(segundos);
  //lcd.print("Temperatura: ");
  lcd.setCursor(3, 1);

  temperatura = (float(analogRead(LM35)) * 5 / (1023)) / 0.01;
  //Serial.print("Temperatura: ");
  //Serial.println(temperatura);
  Serial.println(buttonState);
  lcd.print(temperatura);
  delay(1000);
  //função de contagem do relogio
  conta();
}
