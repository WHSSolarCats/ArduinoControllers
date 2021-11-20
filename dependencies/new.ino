//
//17.11.2021
//Lukas Robin
//

#include <stdlib.h>
#define ENC_COUNT_REV 620
#define ENC_IN_RIGHT_A 2
#define ENC_IN_RIGHT_B 4

#define DATA1 5
#define DATA2 6
#define DATA3 7
#define DATA4 8
#define DATA5 9
#define DATA6 10
#define DATA7 11

bool Direction_right = true;
volatile long right_wheel_pulse_count = 0;
int interval = 100;
long previousMillis = 0;
long currentMillis = 0;
float rpm_right = 0;
float ang_velocity_right = 0;
float ang_velocity_right_deg = 0;
 
void setup(){
  pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
  pinMode(ENC_IN_RIGHT_B , INPUT);
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_pulse, RISING);
  Serial.begin(9600);
  pinMode(DATA1, OUTPUT);
  pinMode(DATA2, OUTPUT);
  pinMode(DATA3, OUTPUT);
  pinMode(DATA4, OUTPUT);
  pinMode(DATA5, OUTPUT);
  pinMode(DATA6, OUTPUT);
  pinMode(DATA7, OUTPUT);
}
 
int get_angular_velocity(){
  currentMillis = millis();
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    rpm_right = (float)(right_wheel_pulse_count * 60 / ENC_COUNT_REV);
    
    right_wheel_pulse_count = 0;
   return rpm_right;
  }
}
int decimalToBinary(int n) {
    int remainder, m;
    int binary = 0, i = 1;
    while(n != 0) {
        remainder = n%2;
        n = n/2;
        binary = binary + (remainder*i);
        i = i*10;
    }
  return binary;
} 
// Increment the number of pulses by 1
void right_wheel_pulse(){
   
  // Read the value for the encoder for the right wheel
  int val = digitalRead(ENC_IN_RIGHT_B);
 
  if(val == LOW) {
    Direction_right = false; // Reverse
  }
  else {
    Direction_right = true; // Forward
  }
   
  if (Direction_right) {
    right_wheel_pulse_count++;
  }
  else {
    right_wheel_pulse_count--;
  }
}

 char* velocity_array(){
  ang_velocity_right = get_angular_velocity();
  int angular_vel = decimalToBinary(ang_velocity_right);
  char *binary_vel = (char*)malloc(7);
  for (int i = 0; i < 8; i++) {
    if (angular_vel & (1 << i)) {
      binary_vel[7-i] = "1";
    }
    else {
      binary_vel[7-i] = "0";
    }
  }
  return binary_vel;
}

void loop(){
  const char* velocity[] = {velocity_array()};

    if (velocity[0] == "1"){digitalWrite(DATA1, HIGH);}else{digitalWrite(DATA1, LOW);}
    if (velocity[1] == "1"){digitalWrite(DATA2, HIGH);}else{digitalWrite(DATA2, LOW);}
    if (velocity[2] == "1"){digitalWrite(DATA3, HIGH);}else{digitalWrite(DATA3, LOW);}
    if (velocity[3] == "1"){digitalWrite(DATA4, HIGH);}else{digitalWrite(DATA4, LOW);}
    if (velocity[4] == "1"){digitalWrite(DATA5, HIGH);}else{digitalWrite(DATA5, LOW);}
    if (velocity[5] == "1"){digitalWrite(DATA6, HIGH);}else{digitalWrite(DATA6, LOW);}
    if (velocity[6] == "1"){digitalWrite(DATA7, HIGH);}else{digitalWrite(DATA7, LOW);}
 
}