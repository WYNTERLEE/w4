#include <Stepper.h> //引入步進馬達函示庫

 int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 10; //馬達旋轉速度

//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
  pinMode(25,INPUT);
  pinMode(26,INPUT);
}

void loop() {

 
 
  //倒轉一圈
  if(digitalRead(26)==HIGH){
    stepsPerRevolution=2048;
    myStepper.step(-stepsPerRevolution);
  }
   //正轉一圈
  else if(digitalRead(25)==HIGH){
    stepsPerRevolution=2048;
    myStepper.step(stepsPerRevolution);
  }
  else{
     stepsPerRevolution=0;
    }
}
