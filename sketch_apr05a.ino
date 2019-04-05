// Тестировалось на Arduino IDE 1.0.5
int IN3 = 5; // Input3 подключен к выводу 5 
int IN4 = 4;
int IN1 = 10; // Input1 подключен к выводу 9
int IN2 = 9;

void setup()
{
  pinMode (IN4, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
}
void loop()
{
  // На пару выводов "IN" поданы разноименные сигналы, мотор вращается   
  digitalWrite (IN4, HIGH);
  digitalWrite (IN3, LOW);
  digitalWrite (IN2, HIGH);
  digitalWrite (IN1, LOW); 
  delay(10000);
  // На пару выводов "IN" поданы одноименные сигналы, мотор не вращается 
  digitalWrite (IN4, LOW); 
  digitalWrite (IN2, LOW); 
  delay(500);
  // На пару выводов "IN" поданы разноименные (и уже противоположные относительно первого случая) сигналы, мотор вращается  
  // относительно первого случая) сигналы, мотор вращается в другую сторону
  digitalWrite (IN3, HIGH);
  digitalWrite (IN1, HIGH);
  delay(2000);
  // Снова на выводах "IN" появились одноименные сигналы, мотор не вращается 
  digitalWrite (IN3, LOW); 
  digitalWrite (IN1, LOW); 
  delay(5000);
}
