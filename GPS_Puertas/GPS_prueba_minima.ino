#include <TinyGPS.h>

/* 
   Este código prueba el GPS de la forma mas básica posible
   Solo entrega la latitud y longitud.
*/

TinyGPS gps;
float flat, flon;
void setup()
{
  Serial.begin(115200); //puerto con el que arduino conversa con el PC
                        //PONER EL MONITOR SERIAL A ESTA VELOCIDAD!!!!!
   
  Serial1.begin(9600);  //puerto con que arduino conversa con el GPS
}

void loop()
{
    while (Serial1.available()){
      char c = Serial1.read();   //Se lee el puerto serial del GPS (Serial1) 
      if (gps.encode(c)){        //se pasa la variable C al gps 
         
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age); //se le pide al GPS la posicion
      Serial.print("LAT=");      //Se muestran los datos en el serial del PC (SERIAL solo)
      Serial.print(flat, 6);
      Serial.print(" LON=");
      Serial.println(flon, 6);
      }
    }
}
