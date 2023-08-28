#include<Servo.h>
Servo myservo;
int i;
void setup() {  
  i=0;        
  pinMode(A0,INPUT); 
  pinMode(A1,INPUT); 
  pinMode(A2,INPUT); 
  myservo.attach(9); 
  Serial.begin(9600); 
}
int threshold1=400,threshold2,threshold3; 
int LDR01,LDR02,LDR03; 
// LDR01 -> <210= BLACK background

void loop() {
   LDR01=analogRead(A0); //for background
   LDR02=analogRead(A1); //for cactus
   LDR03=analogRead(A2); // for cactus
  
  Serial.print(LDR01); 
  Serial.print(" "); 
  Serial.print(LDR02); 
  Serial.print(" "); 
  Serial.print(LDR03); 
  Serial.print("\n");  
   if(LDR01<threshold1){ // BLACK BACKGROUND
   // Serial.print("BLACK BG ");
    threshold2=350;
    threshold3=360;
   
    if(LDR02>threshold2||LDR03>threshold3){
      if(i<68)i++;
      Serial.print(" BLACK BG -> WHITE cactus detected\n");
//     if(LDR02>threshold2)
//      delay(150-50*(i/17));
//      else
        delay(150-50*(i/17));
        Serial.println(i);
      myservo.write(25-(i/50)); 
      
            delay(50);
    }else{
      
      //Serial.print(" BLACK BG -> WHITE cactus not detected\n");
      myservo.write(10); 
    }
  }else{ // WHITE BACKGROUND
   // Serial.print("WHITE BG ");
    threshold2=510; 
    threshold3=590; 
    if(LDR02<threshold2||LDR03<threshold3){
      if(i<68) i++;
      Serial.print("WHITE BG -> BLACK cactus detected\n");
 
//      if(LDR02<threshold2)
//      delay(150-50*(i/17));
//      else
        delay(160-50*(i/17));
        Serial.println(i);
      myservo.write(25-(i/50)); 
      
            delay(50);

    }else{
      //Serial.print("WHITE BG -> BLACK cactus not detected\n");
      myservo.write(10); 
    }
  }
}
