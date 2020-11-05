//Programa Laboratorio 5 tercer corte
//Andrés Gómez CODIGO 2154714 David Sandoval codigo 2142786
//Version 1.0

class inputs{ //clase para entradas
 private:
 
 int S0;//DPSW1
 int S1;//DPSW2
 int S2;//DPSW3
 int S3;//DPSW4
 int Z;// ENTRADA ANALOGA
 public:
 
 void set_input_ports( int s00, int s01, int s02, int s03,int an) //asignacion de puertos de entrada

 {
  S0=s00;
  S1=s01;
  S2=s02;
  S3=s03;
  Z=an;

 }
 void config_inputs()//configuración de entradas

 {

 pinMode(S0, INPUT);//entradas digitales
 pinMode(S1, INPUT);
 pinMode(S2, INPUT);
 pinMode(S3, INPUT);
 pinMode(Z,  INPUT);


 }
  int read_input(int in) //leer y retornar el valor leido

 {
 int val;
 val=digitalRead(in);//lee el puerto indicado
 return val;


 }
 int read_analog_input(int in)//lee y retorna el valor analogo convertido a digital 

 {
 int val;
 val=analogRead(in);//leer puerto analogo indicado
 return val;

 }
    
};

class led_control{//clase para salidas

 private:

 int led1;
 int led2;
 int led3;
 int led4;


 public:


 void set_led_ports(int p1, int p2, int p3, int p4)//set de los puertos de salida

 {
 led1=p1;
 led2=p2;
 led3=p3;
 led4=p4;
 }

 void config_leds()//se declara que son puertos de salida
 {
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 }

 void set_leds(int led)

 {
 digitalWrite(led, HIGH);//funcion para encender led 
 }

 void clear_leds(int led)

 {
 digitalWrite(led, LOW);//funcion para apagar led
 }
 };

//se crean los objetos a utilizar
inputs entradas;
led_control leds_ejemplo;



void setup()//configuracion 

 {
 entradas.set_input_ports(6,7,8,9,5);//puertos de entrada segun el montaje fisico
  
 entradas.config_inputs();// se configuran los puertos como entrada

 leds_ejemplo.set_led_ports(2,3,4,5);// indicamos los puertos de saluda segun el montaje fisico

 leds_ejemplo.config_leds();
 Serial.begin(9600);//iniciar velocidad de intercambio de datos con el monitor serial 
 
 }



void loop()//principal  

 {
  //inicia el ciclo del programa principal
  //declaramos los valores para usar en las funciones 
int S0=6;
int S1=7;
int S2=8;
int S3=9;
int val=0;
int Z=5;
val=entradas.read_analog_input(Z);//lee entrada analógica
Serial.println(val);//imprime entrada analoga 
delay(1);//delay de 1ms para percibir los datos en el monitor serial 

 if (entradas.read_input(S3) == HIGH ){// evalúa el dpsw3 para saber que modo elige 
      modo1();//passthrough
      leds_ejemplo.clear_leds(5);
      }
 
 else{      
      modo2();//Analog Reference
      }
      
 }

 void modo2(){//Modo Analog Reference
  //declara los valores que se van a mandar a las funciones 
int S0=6;
int S1=7;
int S2=8;
int S3=9;
int Z=5;
int led1=2;
int led2=3;
int led3=4;
int led4=5;
int tol;
tol=tolerancia();//se recibe el valor para  elegir el caso 
switch(tol){

  case 7:

         //el valor de referencia es 536
         //para +- 7%
              
              if (entradas.read_analog_input(Z)>574) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<574 && entradas.read_analog_input(Z)>498)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<498)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;
              
        case 6:
              //para +- 6%

               if (entradas.read_analog_input(Z)>568) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<568 && entradas.read_analog_input(Z)>504)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<504)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }           
              break;
       case 5://para +- 5% 

               if (entradas.read_analog_input(Z)>563) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<563 && entradas.read_analog_input(Z)>509)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<509)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }       
              break;
        case 4://para +- 4%

               if (entradas.read_analog_input(Z)>557) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<557 && entradas.read_analog_input(Z)>515)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<515)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              } 
              break;

       case 3://para +- 3%

               if (entradas.read_analog_input(Z)>552) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<552 && entradas.read_analog_input(Z)>520)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<520)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1); 
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;
              
         case 2://para +- 2%

               if (entradas.read_analog_input(Z)>547) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if (entradas.read_analog_input(Z)<547 && entradas.read_analog_input(Z)>525)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2); 
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<525)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              }
              break;

          case 1://para +- 1%

              if (entradas.read_analog_input(Z)>541) //si supera la tolerancia positiva
              {
                leds_ejemplo.set_leds(led3);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              
              
              else if(entradas.read_analog_input(Z)<541 && entradas.read_analog_input(Z)>531)//si se encuentra dentro del rango de tolerancias
              {
                leds_ejemplo.set_leds(led2);
                 leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              }
              

              else if (entradas.read_analog_input(Z)<531)//si supera la tolerancia negativa
              {
                leds_ejemplo.set_leds(led1);
                 leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led2);
              } 
              break;  
         default://para +-0%

             if (entradas.read_analog_input(Z)==536)//solo enciende con el valor de referencia
              {
                leds_ejemplo.set_leds(led2);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led3);
              } 
              else{
                leds_ejemplo.clear_leds(led3);
                leds_ejemplo.clear_leds(led1);
                leds_ejemplo.clear_leds(led2);
              }
              break;  
              


}
  
 }
void modo1(){//Modo Passthrough
  // se declaran los valores que se van a enviar a las funciones
int S0=6;
int S1=7;
int S2=8;
int S3=9;

    if (entradas.read_input(S3) == HIGH ){//si dpsw3 está activo
      
      leds_ejemplo.set_leds(5);
 
      }
      else{
      leds_ejemplo.clear_leds(5);
      }
    if (entradas.read_input(S1) == HIGH ){//si dpsw2 está activo

      leds_ejemplo.set_leds(5);
      leds_ejemplo.set_leds(3);
      }
      else{
      leds_ejemplo.clear_leds(3);
 
      }
    if (entradas.read_input(S2) == HIGH ){  //si dpsw1 está activo
 
      leds_ejemplo.set_leds(2);
      leds_ejemplo.set_leds(5);
      }
      else{
      leds_ejemplo.clear_leds(2);
     
      }
    if (entradas.read_input(S0) == HIGH ){  //si dpsw0 está activo

      leds_ejemplo.set_leds(4);
      }
      else{
      leds_ejemplo.clear_leds(5);
      leds_ejemplo.clear_leds(4);
      }
   
 }
int tolerancia(){//funcion para devolver el valor de la tolerancia seleccionada
  //se declaran los valores que se envían a las funciones 
  int S0=6;
  int S1=7;
  int S2=8;
  int S3=9;
  int caso=0;//valor a devolver 
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==HIGH){//si es 7 en binario
      caso=7;
      return caso;
     }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==LOW){//si es 6 en binario
      caso=6;
      return caso;
     }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==LOW && entradas.read_input(S0)==HIGH){//si es 5 en binario
       caso=5;
       return caso;
     }
  if (entradas.read_input(S2)==HIGH && entradas.read_input(S1)==LOW && entradas.read_input(S0)==LOW){//si es 4 en binario
       caso=4;
       return caso;
      }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==HIGH){//si es 3 en binario
       caso=3;
       return caso;
      }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==HIGH && entradas.read_input(S0)==LOW){//si es 2 en binario
       caso=2;
       return caso;
      }
  if (entradas.read_input(S2)==LOW && entradas.read_input(S1)==LOW && entradas.read_input(S0)==HIGH){//si es 1 en binario
      caso=1;
      return caso;
      }
  return caso;//si es 0 en binario, ninguno está activo
}
 
