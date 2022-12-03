// L298N Çift Motor Sürücü
const int motor_sol_on    = 5;  // IN3
const int motor_sol_arka  = 6;  // IN1
const int motor_sag_on    = 10; // IN2
const int motor_sag_arka  = 9;  // IN4

// Süper-sonik Dalga Sensörleri
#define echoPin 12
#define trigPin 13
int süre;
int uzaklik;

const char engeller [500];
const bool engelhali = false;
const int index = 0;
bool harakethali = false;

int x = 0;
int y = 0;
int xsüre = 0;
int ysüre = 0;

int state;
int motor_hızı = 0; // Saniye başına gidilecek max mesafe (l = m)

void setup() {
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(motor_sol_on, OUTPUT);
  pinMode(motor_sol_arka, OUTPUT);
  pinMode(motor_sag_on, OUTPUT);
  pinMode(motor_sag_arka, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    state = Serial.read();
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  uzaklik = sure / 29.1 / 2;

  if (uzaklik < 16) {
    engeller[index] = char(x) + "," + char(y);
    index++;
    engelhali = true;

    analogWrite(motor_sol_on, 0);
    analogWrite(motor_sol_arka, 0);
    analogWrite(motor_sag_on, 0);
    analogWrite(motor_sag_arka, 0);
    delay(200);

    analogWrite(motor_sol_arka, 255);
    analogWrite(motor_sag_arka, 255);
    delay(600);

    analogWrite(motor_sol_on, 0);
    analogWrite(motor_sol_arka, 0);
    analogWrite(motor_sag_on, 0);
    analogWrite(motor_sag_arka, 0);
    engelhali = false;
  }

  if (engelhali !== true) {
    if (state == "F" or state == "B") {
      analogWrite(motor_sol_on, 255);
      analogWrite(motor_sol_arka, 255);
      analogWrite(motor_sag_on, 255);
      analogWrite(motor_sag_arka, 255);
      harakethali = true;
      if (state == "F") ysüre++;
      if (state == "B") ysüre = ysüre - 1;
    }
    else if (state == "R") {
      analogWrite(motor_sol_on, 255);
      analogWrite(motor_sol_arka, 255);
      analogWrite(motor_sag_on, 0);
      analogWrite(motor_sag_arka, 0);
      harakethali = true;
      xsüre++;
    }
    else if (state == "L") {
      analogWrite(motor_sol_on, 0);
      analogWrite(motor_sol_arka, 0);
      analogWrite(motor_sag_on, 255);
      analogWrite(motor_sag_arka, 255);
      harakethali = true;
      xsüre = xsüre - 1
    }
    else if (state == "S") {
      analogWrite(motor_sol_on, 0);
      analogWrite(motor_sol_arka, 0);
      analogWrite(motor_sag_on, 0);
      analogWrite(motor_sag_arka, 0);
      harakethali = true;
    }
  }
  if (harakethali == true) {
    x = xsüre + (xsüre / 1000);
    y = ysüre + (ysüre / 1000);
    harakethali = false;
  }
}