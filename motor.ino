/*****************
 * Control de un servomotor con un 
 * potenciometro
 * ***************
 *  Este programa permite controlar la posicion angular de un
 *  servomotor a traves de un potenciometro
 *******************/
 #include<Servo.h>        //Libreria para servomotores
 Servo Mi_Servo;          //Creamos un objeto para el servomotor
 int Pin_Servo = 9;       //Seclaramos el puerto 9 para el servomotor.
 int Potenciometro = A0;  //Puerto analógico A0 para el potenciometro
 long Valor_analog = 0;   //Variable de almacenamiento de valores analogicos
 int Angulo = 0;          //Variable para guardar el angulo de guro del servo.

void setup()
{
  Mi_Servo.attach(Pin_Servo); //Posicionar el servo al puerto 9
  }
  void loop()
  {
    /*
    Realizamos una suma de 100 valores analogicos para eliminar 
    un poco el ruido del potenciometro
    */
    for(int x=0;x<100;x++)
    {
      Valor_analog += analogRead(Potenciometro); //Leemos los datos analógicos
      }
      
      Valor_analog = Valor_analog/100;  //Calculamos la media aritmetica de la suma
      Angulo = map(Valor_analog,0,1023,0,180);  //Mapeamos los valores analogicos a angulos de giro
      Mi_Servo.write(Angulo); //Escribimos la posicion del angulo al puerto del servo
  }