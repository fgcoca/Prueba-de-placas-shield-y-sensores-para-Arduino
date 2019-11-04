#include "Adafruit_CCS811.h"
Adafruit_CCS811 ccs;

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba basica del sensor CCS811");
  
  if(!ccs.begin()){
    Serial.println("¡Error iniciando el sensor! Por favor revisar conexionado.");
    while(1);
  }
  //calibración del sensor de temperatura
  while(!ccs.available());
  float temperatura = ccs.calculateTemperature();
  ccs.setTempOffset(temperatura - 20.0); //ajuste temperatura
}

void loop() {
  if(ccs.available()){
    float temperatura = ccs.calculateTemperature();
    if(!ccs.readData()){ //si no está tomando lectura enviar datos
      Serial.print("CO2: ");
      Serial.print(ccs.geteCO2());
      Serial.print(" ppm, TVOC: ");
      Serial.print(ccs.getTVOC());
      Serial.print(" ppb  ---  Temperatura: ");
      Serial.print(temperatura);
      Serial.println(" *C");
    }
    else{
      Serial.println("¡ ERROR !");
      while(1);
    }
  }
  delay(10000);
}
