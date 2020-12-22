#define SENSOR_PIN 8
void setup() {
  Serial.begin(9600);
  pinMode(SENSOR_PIN, INPUT);
  Serial.println("time[s] odoms omega[ob/s]");

}
long int odoms = 0;
long int ts = 0;
float omega = 0;
void loop() {
  
  ts = pulseIn(SENSOR_PIN, LOW);
  if(ts)
  {
    odoms += 1;
    omega = 1 / (8 * 1e-6 * (float)ts); 
    Serial.print(ts);
    Serial.print(" ");
    Serial.print(odoms);
    Serial.print(" ");
    Serial.println(omega);
    
  }
 
}
