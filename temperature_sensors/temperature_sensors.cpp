int sensor_pin = 0;




void setup(){
  Serial.begin(9600);
  client.begin(9600);
  wifi_init();
   Serial.println("System Ready..");
}

float get_temperature(){
  int sensor_pin_in = analogRead(sensor_pin);
  float voltage = sensor_pin_in * 5.0;
  voltage /= 1024.0;
  Serial.print("Sensor voltage: "); Serial.println(voltage);
  float temperature = (voltage - 0.5) * 100;
  return temperature;
}
void loop(){
  
}