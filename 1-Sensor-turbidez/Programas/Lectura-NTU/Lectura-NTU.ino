/* ----------------------------------------------------------------------------------------------------------  
// Programa...: Lectura-NTU.ino   
// Autor......: @fgcoca (octubre-2019)  
// Descripción: Visualización del valor de tensión y de turbidez en NTU en el terminal serie.  
// ---------------------------------------------------------------------------------------------------------- */  
#define Turbidy_sensor A0   
float Tension = 0.0;  
float NTU = 0.0;  
void setup() {   
  Serial.begin(9600); // Velocidad de comunicación  
  Serial.println("Lectura del sensor de turbidez y expresión del resultado en unidades nefelometricas");  
  Serial.println("===================================================================================");  
  Serial.println(" ");  
  Serial.println("Tension\tNTU");   
  Serial.println("-------\t---");  
}  
void loop() {  
  Tension = 0;  
  Tension = analogRead(Turbidy_sensor)/1024*5; // Mapeo de la lectura analógica  
  //Para compensar el ruido producido en el sensor tomamos 500 muestras y obtenemos la media  
  for(int i=0; i<500; i++)  
    {  
      Tension += ((float)analogRead(Turbidy_sensor)/1024)*5;  
    }  
    Tension = Tension/500;  
    Tension = redondeo(Tension,1);  
    //Para ajustarnos a la gráfica de la derecha  
    if(Tension < 2.5){  
      NTU = 3000;  
    }else{  
      NTU = -1120.4*square(Tension)+5742.3*Tension-4352.9;   
    }  
  //Envio de valores y textos al terminal serie  
  Serial.print(Tension);  
  Serial.print(" V");  
  Serial.print("\t");  
  Serial.print(NTU);  
  Serial.println(" NTU");  
  delay(5000);  
}  

float redondeo(float p_entera, int p_decimal)  
{  
  float multiplicador = powf( 10.0f, p_decimal);  //redondeo a 2 decimales  
  p_entera = roundf(p_entera * multiplicador) / multiplicador;  
  return p_entera;  
}
