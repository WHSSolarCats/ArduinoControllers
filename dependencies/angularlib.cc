
#define ENC_COUNT_REV 600
#define ENC_IN_RIGHT_A 2
#define ENC_IN_RIGHT_B 4

//define the data bands up to 16 bits
#define DATA1 22
#define DATA2 24
#define DATA3 26
#define DATA4 28
#define DATA5 30
#define DATA6 32
#define DATA7 34
#define DATA8 36
#define DATA9 38
#define DATA10 40
#define DATA11 42
#define DATA12 44
#define DATA13 46
#define DATA14 48
#define DATA15 50
#define DATA16 52
 
// True = Forward; False = Reverse
bool Direction_right = true;
 
// Keep track of the binary_rpm of right wheel pulses
volatile long right_wheel_pulse_count = 0;
 
// One-second interval for measurements
int interval = 1000;
  
// Counters for milliseconds during interval
long previousMillis = 0;
long currentMillis = 0;
 
// Variable for RPM measuerment
float rpm_right = 0;
 
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
    pinMode(DATA8, OUTPUT);
    pinMode(DATA9, OUTPUT);
    pinMode(DATA10, OUTPUT);
    pinMode(DATA11, OUTPUT);
    pinMode(DATA12, OUTPUT);
    pinMode(DATA13, OUTPUT);
    pinMode(DATA14, OUTPUT);
    pinMode(DATA15, OUTPUT);
    pinMode(DATA16, OUTPUT);
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
    rpm_right = (float)(right_wheel_pulse_count * 60 / ENC_COUNT_REV);
    binary_rpm = decimalToBinary(rpm_right);
    int n1,n2,n3,n4,n5,n6,n7,n8,n9,n10,n11,n12,n13,n14,n15;
    n1 = binary_rpm%10;
    binary_rpm /= 10;
    n2 = binary_rpm%10;
    binary_rpm /= 10;
    n3 = binary_rpm%10;
    binary_rpm /= 10;
    n4 = binary_rpm%10;
    binary_rpm /=10;
    n5 = binary_rpm%10;
    binary_rpm /= 10;
    n6 = binary_rpm%10;
    binary_rpm /= 10;
    n7 = binary_rpm%10;
    binary_rpm /= 10;
    n8 = binary_rpm%10;
    binary_rpm /= 10;
    n9 = binary_rpm%10;
    binary_rpm /= 10;
    n10 = binary_rpm%10;
    binary_rpm /= 10;
    n11 = binary_rpm%10;
    binary_rpm /= 10;
    n12 = binary_rpm%10;
    binary_rpm /= 10;
    n13 = binary_rpm%10;
    binary_rpm /= 10;
    n14 = binary_rpm%10;
    binary_rpm /= 10;
    n15 = binary_rpm%10;
    binary_rpm /= 10;
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
    if (n8){
        digitalWrite(DATA8, HIGH);
        }
        else{
        digitalWrite(DATA8, LOW);
        }
    if (n9){
        digitalWrite(DATA9, HIGH);
        }
        else{
        digitalWrite(DATA9, LOW);
        }
    if (n10){
        digitalWrite(DATA10, HIGH);
        }
        else{
        digitalWrite(DATA10, LOW);
        }
    if (n11){
        digitalWrite(DATA11, HIGH);
        }
        else{
        digitalWrite(DATA11, LOW);
        }
    if (n12){
        digitalWrite(DATA12, HIGH);
        }
        else{
        digitalWrite(DATA12, LOW);
        }
    if (n13){
        digitalWrite(DATA13, HIGH);
        }
        else{
        digitalWrite(DATA13, LOW);
        }
    if (n14){
        digitalWrite(DATA14, HIGH);
        }
        else{
        digitalWrite(DATA14, LOW);
        }
    if (n15){
        digitalWrite(DATA15, HIGH);
        }
        else{
        digitalWrite(DATA15, LOW);
        }
    if (n16){
        digitalWrite(DATA16, HIGH);
        }
        else{
        digitalWrite(DATA16, LOW);
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