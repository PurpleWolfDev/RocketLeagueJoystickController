#include <math.h>
const int pushButton3 = 2;
const int vX1 = A0;
const int vY1 = A1;
const int pushButton1 = 3;
const int pushButton2 = 4;
char currentMovement = 'n';
char oldDirn = 'n';
int boost = 0;
int right = 0;
int shift = 0;
// We will use ojbect based communication
// {dirn:'', boost:0/1, right:0/1, shift:0,1};
// w - fw
// s - bw
// q - fwr
// e - fwl
// r - bwr
// t - bwl


void setup() {
  pinMode(pushButton3, INPUT_PULLUP);
  pinMode(pushButton1, INPUT_PULLUP);
  pinMode(pushButton2, INPUT_PULLUP);
  Serial.begin(9600);
}

char calcDirn(int vX,int vY) {
  int actualVX = vX - 512;
  int actualVY = vY - 512;
  if((abs(actualVX) > 50)||(abs(actualVY) > 50)) {
    if((actualVX > 0)&&(actualVY > 0)) {
      if((actualVY*1.0)/(actualVX*1.0) > 1.73) return 'w';
      return 'q';
    }
    else if((actualVX < 0)&&(actualVY > 0)) {
      if((actualVY*1.0)/(abs(actualVX)) > 1.73) return 'w';
      else return 'e';
    }
    else if((actualVX < 0)&&(actualVY < 0)) {
      if ((double)actualVY / actualVX > 1.73) return 's';
      else return 't';
    }
    else if((actualVX > 0)&&(actualVY < 0)) {
      if ((double)abs(actualVY) / actualVX > 1.73) return 's';
      else return 'r';
    }
  }
  return 'n';
}


void loop() {
  int pushStat1 = digitalRead(pushButton1);
  int pushStat2 = digitalRead(pushButton2);
  int pushStat3 = digitalRead(pushButton3);
  int btn1, btn2, btn3;
  int vX1Read = analogRead(vX1); 
  int vY1Read = analogRead(vY1); 
  vY1Read = 1023 - vY1Read;
  char dirn = calcDirn(vX1Read, vY1Read);
  
  if(pushStat1 == LOW) btn1 = 1; else btn1 = 0;
  if(pushStat2 == LOW) btn2 = 1; else btn2 = 0;
  if(pushStat3 == LOW) btn3 = 1; else btn3 = 0;
  if((dirn != oldDirn) || (btn1 != boost) || (btn2 != right) || (btn3 != shift)) {
      oldDirn = dirn;
      boost = btn1;
      right = btn2;
      shift = btn3; 
      Serial.print("{\"dirn\":");
      Serial.print('"'); 
Serial.print(dirn);   
Serial.print('"');    
      Serial.print(",\"boost\":");
      Serial.print(btn1);
      Serial.print(",\"right\":");
      Serial.print(btn2);
      Serial.print(",\"shift\":");
      Serial.print(btn3);
      Serial.println("}");
  }
  delay(20);
}
