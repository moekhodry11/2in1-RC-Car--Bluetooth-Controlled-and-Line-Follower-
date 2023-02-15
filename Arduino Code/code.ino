#define enA 5 //speed of M1
#define enB 6  //speed of M2
#define in1 11 //if 1 then fwd M1
#define in2 10 //if 1 then bwd M1
#define in3 13 //if 1 then fwd M2
#define in4 12 //if 1 the bwd M2
/* ******** */
#define S_R 8
#define S_L 9
/* ******** */
char mode;
char state;
bool Flag;
void setup() {
  Serial.begin(9600);
  pinMode(S_R,INPUT);
  pinMode(S_L,INPUT);
  pinMode(enA,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop() {
  Stop();
  while(Serial.available()>0){
  mode = Serial.read();
  if (mode == 'V'){
    Flag = 1;
    while (Flag){
      state = Serial.read();
      switch (state)
      {
        case 'F':
          forward();
          delay(5);
          break;
        case 'L':
          right();
          delay(5);
          break;
        case 'R':
          left();
          delay(5);
          break;
        case 'B':
          reverse();
          delay(5);
          break;
        case 'I':
          F_Right();
          delay(5);
          break;
        case 'G':
          F_Left();
          delay(5);
          break;
          case 'H':
          B_Left();
          delay(5);
          break;
        case 'J':
          B_Right();
          delay(5);
          break;
        case 'S':
          Stop();
          delay(5);
          break;
        case 'W':
          Flag=0;
          break;
        case 'w':
          Flag=0;
          break;
      }
      //Stop();
    }
  }
  else if (mode == 'v' )
  {
    Flag = 1;
  while(Flag){
  if(digitalRead(S_R) == 1 && digitalRead(S_L) == 0){
    right();
  }
  else if(digitalRead(S_R) == 0 && digitalRead(S_L) ==1){
    left();
  }
  else if(digitalRead(S_R) == 0 && digitalRead(S_L) ==0){
    forward();
  }
  else if(digitalRead(S_R) == 1 && digitalRead(S_L) ==1){
    Stop();
    }
  /*else if (mode =='2'){
    Obstacle();
  }*/
  char x = Serial.read();
    if (x=='W'){
      Flag = 0;
    }
    else if (x=='w'){
      Flag = 0;
    }
  }
  }
  }
}

void forward(){
  digitalWrite(enA,1);
  digitalWrite(enB,1);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
  
}
void right(){
  analogWrite(enA,255);
  analogWrite(enB,255);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}
void left(){
  analogWrite(enA,255);
  analogWrite(enB,255);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
}
void reverse()
{
  analogWrite(enA,150);
  analogWrite(enB,150);
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}
void Stop()
{
  analogWrite(enA,0);
  analogWrite(enB,0);
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,0);
}
void B_Left(){
  analogWrite(enA,255/2);
  //analogWrite(enB,255/2);
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}
void B_Right(){
  //analogWrite(enA,255/2);
  analogWrite(enB,255/2);
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
}
void F_Right(){
  //analogWrite(enA,255/2);
  analogWrite(enB,255/2);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}
void F_Left(){
  analogWrite(enA,255/2);
  //analogWrite(enB,255/2);
  digitalWrite(in1,1);
  digitalWrite(in2,0);
  digitalWrite(in3,1);
  digitalWrite(in4,0);
}