class led_control{
  private:
    int led1;
    int led2;
    int led3;
    int led4;
    
    int S0;
    int S1;
    int S2;
    int S3;

    int Z;
  
  public:
   
    void set_led_ports(int p1, int p2, int p3, int p4, int s00, int s01, int s02, int s03, int pot)  // declara los leds como valores enteros para manejarlos
    {
      led1=p1;
      led2=p2;
      led3=p3;
      led4=p4;

      S0=s00;
      S1=s01;
      S2=s02;
      S3=s03;

      Z=pot;
      
    }
    void config_leds()//declarar salidas y entradas
    {
      pinMode(led1, OUTPUT);//declara que son salidas
      pinMode(led2, OUTPUT);//declara que son salidas
      pinMode(led3, OUTPUT);
      pinMode(led4, OUTPUT);
      
      pinMode(S0, INPUT);//entradas digitales
      pinMode(S1, INPUT);
      pinMode(S2, INPUT);
      pinMode(S3, INPUT);

      pinMode(Z, INPUT);
    }

    void inicializacion()
    {
   
      while (digitalRead(S3)==HIGH){
      digitalWrite(led4, HIGH);
      modo1();}
        if (digitalRead(S3)==LOW){      
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
           }
     if (digitalRead(S3)==LOW){
      modo2();}                  
    }

    void modo1()
    {
      if (digitalRead(S0) == HIGH ){
      digitalWrite(led3, HIGH);
      }
      else{
      digitalWrite(led3, LOW);    
      }
         
      if (digitalRead(S1) == HIGH ){
      digitalWrite(led2, HIGH);
      }
      else{
      digitalWrite(led2, LOW);    
      }
      
      if (digitalRead(S2) == HIGH ){
      digitalWrite(led1, HIGH);
      }
      else{
      digitalWrite(led1, LOW);       
      }
      //inicializacion();
    }
    

    void modo2()
    {
        if (digitalRead(S3)==LOW && digitalRead(S2)==HIGH && digitalRead(S1)==HIGH && digitalRead(S0)==HIGH){ //para +- 7%
              
              while (analogRead(Z)>573) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<573 && analogRead(Z)>498)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<498)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              }
        }
              
        if (digitalRead(S3)==LOW && digitalRead(S2)==HIGH && digitalRead(S1)==HIGH && digitalRead(S0)==LOW){//para +- 6%

              while (analogRead(Z)>568) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<568 && analogRead(Z)>503)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<503)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              }           
        }
        if (digitalRead(S3)==LOW && digitalRead(S2)==HIGH && digitalRead(S1)==LOW && digitalRead(S0)==HIGH){//para +- 5% 

              while (analogRead(Z)>562) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<562 && analogRead(Z)>509)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<509)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              }       
        }
        if (digitalRead(S3)==LOW && digitalRead(S2)==HIGH && digitalRead(S1)==LOW && digitalRead(S0)==LOW){//para +- 4%

              while (analogRead(Z)>557) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<557 && analogRead(Z)>514)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<514)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              } 
        }
        if (digitalRead(S3)==LOW && digitalRead(S2)==LOW && digitalRead(S1)==HIGH && digitalRead(S0)==HIGH){//para +- 3%

              while (analogRead(Z)>552) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<552 && analogRead(Z)>520)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<520)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              }
        }
              
              if (digitalRead(S3)==LOW && digitalRead(S2)==LOW && digitalRead(S1)==HIGH && digitalRead(S0)==LOW){//para +- 2%

              while (analogRead(Z)>547) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<547 && analogRead(Z)>525)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<525)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              }
        } 

              if (digitalRead(S3)==LOW && digitalRead(S2)==LOW && digitalRead(S1)==LOW && digitalRead(S0)==HIGH){//para +- 1%

              while (analogRead(Z)>541) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)<541 && analogRead(Z)>530)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<530)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              } 
        } 
              if (digitalRead(S3)==LOW && digitalRead(S2)==LOW && digitalRead(S1)==LOW && digitalRead(S0)==LOW){//para +- 0%

              while (analogRead(Z)>536) //si supera la tolerancia positiva
              {
                digitalWrite(led3, HIGH);
              }
              
              
              while (analogRead(Z)==536)//si se encuentra dentro del rango de tolerancias
              {
                digitalWrite(led2,HIGH);
              }
              

              while (analogRead(Z)<536)//si supera la tolerancia negativa
              {
                digitalWrite(led1, HIGH);
              } 
        }

          
    }      
    
};  

led_control leds_lab;

void setup()//funcion donde se declaran todas las subrutinas
{
    leds_lab.set_led_ports(2,3,4,5,6,7,8,9,5);
    leds_lab.config_leds();
    Serial.begin(9600);
}

void loop()//funcion principal (como si fuera el main)
{
    int val=0;
    int Z=5;
    leds_lab.inicializacion();
    val=analogRead(Z);
    Serial.println(val);
    delay(20);
} 
