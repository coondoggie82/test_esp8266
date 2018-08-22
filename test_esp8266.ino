 #define reset_pin A0

void setup() {
  // put your setup code here, to run once:
  SerialUSB.begin(9600);
  Serial1.begin(115200);
  pinMode(reset_pin, OUTPUT);
  digitalWrite(reset_pin, LOW);
  delay(500);
  digitalWrite(reset_pin, HIGH);
  delay(500);
  Serial1.println("AT+CIPMUX=1");
  delay(100);
  Serial1.println("AT+CIPSERVER=1");
}

void loop() {
  // put your main code here, to run repeatedly:
  
  while(Serial1.available()>0){
    char n = Serial1.read();
    SerialUSB.print(n);
  }
  while(SerialUSB.available()>0){
    char n = SerialUSB.read();
    Serial1.print(n);  
  }
  delay(1);
}
