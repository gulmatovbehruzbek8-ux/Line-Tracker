#define RF 6   // Right motor forward
#define RB 7   // Right motor backward
#define LF 8   // Left motor forward
#define LB 9   // Left motor backward
#define RA 5  // Right analog
#define LA 10   // Left analog

// 7 IR Sensors //
#define IR1 A0 // Left extreme
#define IR2 A1 // Left hard
#define IR3 A2 // Left
#define IR4 A3 // Center
#define IR5 A4 // Right
#define IR6 A5 // Right hard
#define IR7 A6 // Right extreme
int speed = 200;  



void setup() {
  Serial.begin(9600);
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(RA, OUTPUT);
  pinMode(LA, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR4, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR6, INPUT);
  pinMode(IR7, INPUT);

  delay(1000);

}

void loop() {

  // Reading sensors
  bool LE = analogRead(IR1) < 300 ? 0 : 1;  // Left extreme
  bool LH = analogRead(IR2) < 300 ? 0 : 1;  // Left hard
  bool L  = analogRead(IR3) < 300 ? 0 : 1;  // Left
  bool C  = analogRead(IR4) < 300 ? 0 : 1;  // Center
  bool R  = analogRead(IR5) < 300 ? 0 : 1;  // Right
  bool RH = analogRead(IR6) < 300 ? 0 : 1;  // Right hard
  bool RE = analogRead(IR7) < 300 ? 0 : 1;  // Right extreme

  // If CENTER
  if ((RE == 1) && (RH == 1) && (R == 1) && (C == 0) && (L == 1) && (LH == 1) && (LE == 1)) {
    // Go forward
    analogWrite(RA, speed);   // Speed on RIGHT
    analogWrite(LA, speed);   // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, HIGH);   // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, HIGH);   // Left  motor Forward
  }

  // If RIGHT
  if ((RE == 1) && (RH == 1) && (R == 0) && (C == 1) && (L == 1) && (LH == 1) && (LE == 1)) {
    // Go RIGHT
    analogWrite(RA, speed - 100);  // Speed on RIGHT
    analogWrite(LA, speed);   // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, HIGH);   // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, HIGH);   // Left  motor Forward
  }
  
  // If LEFT
  if ((RE == 1) && (RH == 1) && (R == 1) && (C == 1) && (L == 0) && (LH == 1) && (LE == 1)) {
    // Go forward
    analogWrite(RA, speed);   // Speed on RIGHT
    analogWrite(LA, speed - 100);  // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, HIGH);   // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, HIGH);   // Left  motor Forward
  }
  
  // If HARD RIGHT
  if ((RE == 1) && (RH == 0) && (R == 1) && (C == 1) && (L == 1) && (LH == 1) && (LE == 1)) {
    // Go HARD RIGHT
    analogWrite(RA, speed);   // Speed on RIGHT
    analogWrite(LA, speed);   // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, LOW);    // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, HIGH);   // Left  motor Forward
  }
  
  // If HARD LEFT
  if ((RE == 1) && (RH == 1) && (R == 1) && (C == 1) && (L == 1) && (LH == 0) && (LE == 1)) {
    // Go HARD LEFT
    analogWrite(RA, speed);   // Speed on RIGHT
    analogWrite(LA, speed);   // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, HIGH);   // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, LOW);    // Left  motor Forward
  }
  
  // If EXTREME RIGHT
  if ((RE == 0) && (RH == 1) && (R ==  1) && (C == 1) && (L == 1) && (LH == 1) && (LE == 1)) {
    // Go EXTREME RIGHT
    analogWrite(RA, speed - 150);  // Speed on RIGHT
    analogWrite(LA, speed - 80);   // Speed on LEFT
    digitalWrite(RB, HIGH);   // Right motor Backwards
    digitalWrite(RF, LOW);    // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, HIGH);   // Left  motor Forward
  }
  
  // If EXTREME LEFT
  if ((RE == 1) && (RH == 1) && (R == 1) && (C == 1) && (L == 1) && (LH == 1) && (LE == 0)) {
    // Go EXTREME LEFT
    analogWrite(RA, speed - 150);   // Speed on RIGHT
    analogWrite(LA, speed - 80);  // Speed on LEFT
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, HIGH);   // Right motor Forward
    digitalWrite(LB, HIGH);   // Left  motor Backwards
    digitalWrite(LF, LOW);    // Left  motor Forward
  }

  // If LOFT
  if ((RE == 0) && (RH == 0) && (R == 0) && (C == 0) && (L == 0) && (LH == 0) && (LE == 0)) {
    // STOP
    digitalWrite(RB, LOW);    // Right motor Backwards
    digitalWrite(RF, LOW);    // Right motor Forward
    digitalWrite(LB, LOW);    // Left  motor Backwards
    digitalWrite(LF, LOW);    // Left  motor Forward
  }
}
