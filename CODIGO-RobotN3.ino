#define ENA  6  // Habilitación con PWM
#define IN1  8  // Sentido de giro
#define IN2  7  // Sentido de giro
#define ENB 11  // Habilitación con PWM
#define IN3  9  // Sentido de giro
#define IN4 10  // Sentido de giro

#include <Servo.h>
Servo miServo;
#define pinServo 5

#include <SoftwareSerial.h>BT
#define arduinoRx 2 //Conectar a Tx del módulo BT
#define arduinoTx 3 //Conectar a Rx del módulo BT
SoftwareSerial miBT(arduinoRx,arduinoTx);

void setup() 
{ 
    Serial.begin(9600); //Iniciar puerto serie 
    miBT.begin(9600); //Iniciar módulo bluetooth 


    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(pinServo, OUTPUT);
       
    miServo.attach(pinServo); 
    miServo.write(0);        
    delay(100);              
 
    Serial.println("Robot Futbol Nivel 3 - 2019 - Probot School");
}

void avanzar()
{
    analogWrite (ENA, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    analogWrite (ENB, 200);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void retroceder()
{ 
    analogWrite (ENA, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    analogWrite (ENB, 200);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

void doblarDerecha()
{  
    analogWrite (ENA,  0);  
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    
    analogWrite (ENB, 200);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void doblarIzquierda()
{  
    analogWrite(ENA, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    analogWrite(ENB,  0);  
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);  
}

void rotarDerecha()
{
    analogWrite (ENA, 200);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    
    analogWrite (ENB, 200);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);   
}

void rotarIzquierda()
{ 
    analogWrite (ENA, 200);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    
    analogWrite (ENB, 200);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW); 
}

void detener() 
{ 
    analogWrite (ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    
    analogWrite (ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW); 
}

void patear()
{
    miServo.write(100);
    delay(300);
    miServo.write(0);   
}

void loop() 
{
    if (miBT.available())
    { 
        char letra = miBT.read();
        Serial.write(letra);      
        if      (letra == 'x')    detener(); 
        else if (letra == 'A')    rotarIzquierda(); 
        else if (letra == 'B')    rotarDerecha(); 
        else if (letra == 'C')    avanzar(); 
        else if (letra == 'D')    doblarDerecha(); 
        else if (letra == 'E')    retroceder(); 
        else if (letra == 'F')    doblarIzquierda(); 
        else if (letra == 'G')    patear(); 
        else { 
                detener();
        }
    }
}
