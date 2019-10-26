/* ----------------------------------------------------------------------------------------------------------
// Programa...: Lectura-basica.ino 
// Autor......: @fgcoca (octubre-2019)
// Descripción: Visualización del valor de tensión del sensor de turbidez en el terminal serie.
// ---------------------------------------------------------------------------------------------------------- */
#define Turbidy_sensor A0 
int TurbidySensorValue = 0;
float Tension = 0.0;
void setup() {
  Serial.begin(9600); // Velocidad de comunicación
  Serial.println("Prueba de lectura del sensor de turbidez");
  Serial.println("========================================");
  Serial.println(" ");
  Serial.println("Lectura analogica\tTension"); 
  Serial.println("-----------------\t-------");
}
void loop() {
  TurbidySensorValue = analogRead(Turbidy_sensor); // Lectura del pin analógico 0
  Tension = TurbidySensorValue * (5.0 / 1024.0); // Mapeo de la lectura analógica
  //Envio de valores y textos al terminal serie
  Serial.print(TurbidySensorValue); 
  Serial.print("\t\t\t");
  Serial.print(Tension);
  Serial.println(" V");
  delay(3000);
}
