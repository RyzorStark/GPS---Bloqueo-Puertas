#include <TinyGPS.h>

/* 
   Este código prueba el GPS de la forma mas básica posible
   Solo entrega la latitud y longitud.
*/

TinyGPS gps;
float flat, flon;
int relay1 = 2;
int relay2 = 3; 
double PLAT = -36.989044;
double PLON = -73.158958;
double PBus =(flat,flon);
double Tol = 0.010000;

void setup()
{
  Serial.begin(115200);     //Puerto con el que arduino conversa con el PC
                            //PONER EL MONITOR SERIAL A ESTA VELOCIDAD!!!!!
  pinMode(relay1, OUTPUT);  //Configurar relay1 como Salida
  pinMode(relay2, OUTPUT);  //Configurar relay2 como Salida
  Serial1.begin(9600);      //Puerto con que arduino conversa con el GPS
}

void loop()
{
    while (Serial1.available()){
             char c = Serial1.read();   //Se lee el puerto serial del GPS (Serial1) 
       if (gps.encode(c)){        //se pasa la variable C al gps 
          
       unsigned long age;
         gps.f_get_position(&flat, &flon, &age); //se le pide al GPS la posicion
         long speed=gps.f_speed_kmph();
         Serial.print(" LAT=");      //Se muestran los datos en el serial del PC (SERIAL solo)
         Serial.print(flat, 6);
         Serial.print(" LON=");
         Serial.print(flon, 6);
         Serial.print(" Velocidad=");
         Serial.println(speed, 6);

         if (PBus>PLAT+Tol||PBus<PLAT-Tol||PBus>PLON+Tol||PBus<PLON-Tol)
          digitalWrite(relay1, LOW); // Envia señal baja al relay1
          Serial.println("Puertas Bloqueadas");
         if (PBus<PLAT+Tol||PBus>PLAT-Tol||PBus<PLON+Tol||PBus>PLON-Tol)
          digitalWrite(relay1, HIGH); // Envia señal alta al relay1
          Serial.println("Puertas Desbloqueadas");
         if (PBus>PLAT+Tol||PBus<PLAT-Tol||PBus>PLON+Tol||PBus<PLON-Tol)
          digitalWrite(relay2, LOW); // Envia señal baja al relay2
          Serial.println("Puertas Bloqueadas");
         if (PBus<PLAT+Tol||PBus>PLAT-Tol||PBus<PLON+Tol||PBus>PLON-Tol)
          digitalWrite(relay2, HIGH); // Envia señal alta al relay2
          Serial.println("Puertas Desbloqueadas");

         

              }
    }
}
