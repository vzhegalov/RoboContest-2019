// Тестировалось на Arduino IDE 1.0.5
int IN3 = 5; // Input3 подключен к выводу 5 
int IN4 = 4;
int kn1;
int kn2;
int state;
void setup()
{
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (A0, INPUT);
  pinMode (A1, INPUT);
  Serial.begin(9600);
}
void loop()
{
 kn1 = digitalRead(A0);
 kn2 = digitalRead(A1);
 Serial.println(kn1);
 if(kn2 == 1){
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
 }
 else
 if(kn1 == 1){ 
  digitalWrite (IN3, HIGH);
  digitalWrite (IN4, LOW);
}
  else{
  // На пару выводов "IN" поданы одноименные сигналы, мотор не вращается 
  digitalWrite (IN4, LOW); 
  digitalWrite (IN3, LOW);} 


}
