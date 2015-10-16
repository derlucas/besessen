#define PON1 digitalWrite(2, HIGH);
#define PON2 digitalWrite(3, HIGH);
#define PON3 digitalWrite(4, HIGH);
#define PON4 digitalWrite(5, HIGH);
#define POFF1 digitalWrite(2, LOW);
#define POFF2 digitalWrite(3, LOW);
#define POFF3 digitalWrite(4, LOW);
#define POFF4 digitalWrite(5, LOW);

void setup() {

  pinMode(A0, INPUT_PULLUP);    // button extra 1 (red)
  pinMode(A1, INPUT_PULLUP);    // button extra 2 (red)
  pinMode(A2, INPUT);           // remote A
  pinMode(A3, INPUT);           // remote B
  pinMode(A4, INPUT);           // remote C
  pinMode(A5, INPUT);           // remote D

  pinMode(2, OUTPUT);           // solenoid 1
  pinMode(3, OUTPUT);           // solenoid 2
  pinMode(4, OUTPUT);           // solenoid 3
  pinMode(5, OUTPUT);           // solenoid 4
}

byte button1;
byte button2;

void sequence1() {
  PON1;
  delay(200);
  PON2;
  delay(200);
  POFF1;
  POFF2;
  PON3;
  delay(100);
  PON1;
  POFF3;
  delay(250);
  PON4;
  delay(200);
  POFF1;
  POFF2;
  POFF3;
  POFF4;
}

void sequence2() {
  PON1;
  PON2;
  delay(100);
  POFF1;
  POFF2;
  delay(340);
  PON1;
  PON2;
  delay(90);
  POFF1;
  POFF2;
  delay(190);
  PON3;
  PON1;
  delay(240);
  POFF1;
  POFF3;
  delay(140);
  PON3;
  PON4;
  delay(160);
  POFF3;
  POFF4;
}

void sequence3() {
  PON1;
  delay(200);
  PON2;
  delay(200);
  POFF1;
  POFF2;
  PON3;
  delay(100);
  PON1;
  POFF3;
  delay(250);
  PON4;
  delay(200);
  PON4;
  PON3;
  delay(100);
  POFF4;
  POFF3;
  delay(130);
  PON4;
  PON3;
  delay(200);
  POFF4;
  POFF3;
  delay(230);
  PON1;
  delay(100);
  POFF1;
  delay(200);
  PON1;
  PON2;
  PON3;
  PON4;
  delay(500);
  
  
  
  POFF1;
  POFF2;
  POFF3;
  POFF4;
}


void sequence4() {
  PON1;
  delay(50);
  POFF1;
  delay(30);
  PON2;
  delay(100);
  POFF2;
  delay(30);
  PON3;
  delay(100);
  POFF3;
  delay(60);
  PON4;
  delay(80);
  POFF4;
  
  
  POFF1;
  POFF2;
  POFF3;
  POFF4;
}


uint8_t a = 0;

void loop() {
  
  button1 = digitalRead(A0);
  button2 = digitalRead(A1);
  if(button1 == LOW || button2 == LOW) {
    
    if(button1 == LOW) {
      if(a == 0) {
        sequence1();
        a = 1;
      } else {
        sequence2();
        a = 0;
      }
    } else if(button2 == LOW) {
      sequence4();
      delay(500);
    }
    
  } else {
    /* skip this, because of interference with another remote control
       for urine release
    if(digitalRead(A2) == HIGH) {
      PON1;
    } else {
      POFF1;
    } */
    
    /*if(digitalRead(A3) == HIGH) {
      PON1;
      PON2;
      PON3;
      PON4;
    } else {
      POFF2;
      POFF1;
      POFF3;
      POFF4;
    }*/
    if(digitalRead(A3) == HIGH) {
      sequence4();
    }
    
    if(digitalRead(A4) == HIGH) {
      if(a == 0) {
        sequence1();
        a = 1;
      } else {
        sequence2();
        a = 0;
      }
    }
    if(digitalRead(A5) == HIGH) {
      sequence3();
      delay(500);
    }
  }
  delay(20);
  

}

