/* ----------------------------------------------------------------------------------------------------------
// Programa...: Lectura-digital.ino 
// Autor......: @fgcoca (octubre-2019)
// Descripción: Visualización en el LED onboard (pin 13) del ajuste del potenciometro cómo valor digital.
// ---------------------------------------------------------------------------------------------------------- */
#define Turbidy_sensor 2 //Conectamos el sensor al pin digital 2
//Poner el interruptor el posición D
const int ledPin = 13; //Led onboard

void setup() {
  pinMode(ledPin, OUTPUT); //Configuramos pin 13 como salida
  pinMode(Turbidy_sensor, INPUT); //Configuramos el pin del sensor de turbidez como entrada
}
void loop() {
  if(digitalRead(Turbidy_sensor)==LOW){  //Lectura de la señal del sensor
    digitalWrite(ledPin, HIGH);  //Si el sensor indica nivel bajo (LOW) encendemos el LED
  }
  else{
    digitalWrite(ledPin, LOW);    //Si el sensor indica nivel alto (HIGH) encendemos el LED
  }
}
