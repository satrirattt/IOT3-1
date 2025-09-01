#define SOUND_SPEED   (342)
#define US_TO_CM(t)   ((SOUND_SPEED*t)/20000.0)
#define TIMEOUT_USEC  (40000)
#define ECHO_PIN      (4)
#define TRIG_PIN      (12)

void setup() {
  pinMode( ECHO_PIN, INPUT );
  pinMode( TRIG_PIN, OUTPUT );
  Serial.begin( 9600 );
  Serial.println( "\n\n\nHC-SR04 Ultrasonic Sensor Demo" );
  Serial.flush();
  digitalWrite( TRIG_PIN, LOW );
  while ( digitalRead( ECHO_PIN) ) { delay(1); }
}

uint32_t read_sensor() {
  digitalWrite( TRIG_PIN, HIGH );
  delayMicroseconds( 10 );
  digitalWrite( TRIG_PIN, LOW );
  // Measure the HIGH pulse width (in usec) 
  return pulseIn( ECHO_PIN, HIGH, TIMEOUT_USEC );
}

void loop() {
  uint32_t t_usec = read_sensor();
  Serial.print( "distance(cm): " );      
  if ( t_usec == 0 ) { // no pulse detected
    Serial.println( "---" );    
  } else {   
    Serial.println(US_TO_CM(t_usec) );
  }
  delay(100);
}
