  // Se efita el registro   TCCR1A para lograr tener una se;al pwm en segundo plano
  
  #define fpwm 50 //Frecuencia deseada para el control del servomotor
  int angulo=50; //Porcentaje e ciclo util deseado
  double cicloutil=5;
    unsigned int maxcount=0;    
  
  void setup()
  {
  
    Serial.begin(9600);
    
   TCCR1A=0B10000000;                          // 10 => non inverting mode PWM pin a  00=>Pin B apagado   00=>freq and phase correct PWM Salida por pin OC1A
   TCCR1B=0B00010001;                          /// Reloj del timer con frecuencia de 16MHZ  a travs de ftimer=fsys/N
   maxcount=(16e6 /(2*fpwm ))-1;         /// FPWM= ftimer/(2*(maxcount+1))
   ICR1= maxcount;                         
   
   OCR1A=maxcount*cicloutil/(100);
   TIMSK1 = 0B00100000;     /// Se genera interrupcion al completar el ciclo util del pwm
   sei();   ///Habilitacion de interrupciones globales  
    
  }
  
  void loop()
  {
    
  }
  
  
  ISR(TIMER1_CAPT_vec){  //Interrupt Service Rutine
  
  if(Serial.available()>0){ 
    cicloutil=Serial.parseInt();
    OCR1A=maxcount*cicloutil/(100);
    cicloutil=(angulo*2.5/180)+0.5
  }

  
  }
  
  //Para arduino Nano la salida del pwm configurado es el pin 13(OC1A)
