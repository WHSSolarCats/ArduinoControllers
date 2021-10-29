#define ENC_COUNT_REV 600
#define ENC_IN_RIGHT_A 2
#define ENC_IN_RIGHT_B 4
//define the data bands up to 7 bits
#define DATA1 22
#define DATA2 24
#define DATA3 26
#define DATA4 28
#define DATA5 30
#define DATA6 32
#define DATA7 34
 
// True = Forward; False = Reverse
bool Direction_right = true;
 
// Keep track of the binary_rpm of right wheel pulses
volatile long right_wheel_pulse_count = 0;
 
// One-second interval for measurements
int interval = 1000;
  
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
 
// Variable for RPM measurement
float rpm_right = 0;
float* rpm_right_ptr = &rpm_right;
 
// Variable for angular velocity measurement
float ang_velocity_right = 0;
float ang_velocity_right_deg = 0;
 
 //variable for binary rpms
long binary_rpm;
void setup() {
  // Set pin states of the encoder
    pinMode(ENC_IN_RIGHT_A , INPUT_PULLUP);
    pinMode(ENC_IN_RIGHT_B , INPUT);
    pinMode(DATA1, OUTPUT);
    pinMode(DATA2, OUTPUT);
    pinMode(DATA3, OUTPUT);
    pinMode(DATA4, OUTPUT);
    pinMode(DATA5, OUTPUT);
    pinMode(DATA6, OUTPUT);
    pinMode(DATA7, OUTPUT);
    // Every time the pin goes high, this is a pulse
  attachInterrupt(digitalPinToInterrupt(ENC_IN_RIGHT_A), right_wheel_pulse, RISING);
}
 
void loop() {
  // Record the time
  currentMillis = millis();
  // If one second has passed, print the binary_rpm of pulses
  if (currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;
    // Calculate revolutions per minute
    *rpm_right_ptr = (float)(right_wheel_pulse_count * 60 / ENC_COUNT_REV);
    *rpm_right_ptr = sqrt(*rpm_right_ptr);
    long binary_rpm_i = decimalToBinary(*rpm_right_ptr);
    long* binary_rpm = &binary_rpm_i;
    int n1,n2,n3,n4,n5,n6,n7;
    n1 = *binary_rpm%10;
    *binary_rpm /= 10;
    n2 = *binary_rpm%10;
    *binary_rpm /= 10;
    n3 = *binary_rpm%10;
    *binary_rpm /= 10;
    n4 = *binary_rpm%10;
    *binary_rpm /=10;
    n5 = *binary_rpm%10;
    *binary_rpm /= 10;
    n6 = *binary_rpm%10;
    *binary_rpm /= 10;
    n7 = *binary_rpm%10;
    
    if (n1){
        digitalWrite(DATA1, HIGH);
        }
        else{
        digitalWrite(DATA1, LOW);
        }
    if (n2){
        digitalWrite(DATA2, HIGH);
        }
        else{
        digitalWrite(DATA2, LOW);
        }
    if (n3){
        digitalWrite(DATA3, HIGH);
        }
        else{
        digitalWrite(DATA3, LOW);
        }
    if (n4){
        digitalWrite(DATA4, HIGH);
        }
        else{
        digitalWrite(DATA4, LOW);
        }
    if (n5){
        digitalWrite(DATA5, HIGH);
        }
        else{
        digitalWrite(DATA5, LOW);
        }
    if (n6){
        digitalWrite(DATA6, HIGH);
        }
        else{
        digitalWrite(DATA6, LOW);
        }
    if (n7){
        digitalWrite(DATA7, HIGH);
        }
        else{
        digitalWrite(DATA7, LOW);
        }
    }
    // Reset the pulse count
    right_wheel_pulse_count = 0;
   
  }

long decimalToBinary(long n) {
    int remainder; 
    long binary = 0, i = 1;
   
    while(n != 0) {
        remainder = n%2;
        n = n/2;
        binary= binary + (remainder*i);
        i = i*10;
    }
    return binary;
}
 
// Increment the binary_rpm of pulses by 1
void right_wheel_pulse() {
  // Read the value for the encoder for the right wheel
  int val = digitalRead(ENC_IN_RIGHT_B);
  if (!val) {
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
