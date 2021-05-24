
  int RED1 = 14;
  int RED2 = 15;
  int RED3 = 16;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4,OUTPUT);  // 초음파 센서 1번 Trig 핀
  pinMode(5,INPUT);   // 초음파 센서 1번 센서 Echo 핀
  pinMode(6,OUTPUT);  // 초음파 센서 2번 Trig 핀
  pinMode(7,INPUT);   // 초음파 센서 2번 Echo 핀
  pinMode(8,OUTPUT);  // 초음파 센서 3번 Trig 핀
  pinMode(9,INPUT);   // 초음파 센서 3번 Echo 핀

  pinMode(14,OUTPUT);  // Red1 핀
  pinMode(15,OUTPUT);  // Red2 핀
  pinMode(16,OUTPUT);  // Red3 핀

  digitalWrite(4,LOW);    // Trig 신호 off
  digitalWrite(6,LOW);    // Trig 신호 off
  digitalWrite(8,LOW);    // Trig 신호 off

  digitalWrite(14,LOW);    // Red1 Off
  digitalWrite(15,LOW);    // Red2 off
  digitalWrite(16,LOW);    // Red3 off
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration1, duration2, duration3;
  int cm1, cm2, cm3;
  
  // 초음파 센서 (1번)
  digitalWrite(4,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(4,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(4,LOW);    // Trig 신호 off
  duration1 = pulseIn(5, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm1 = microsecondsToCentimeters(duration1);  // 거리(cm)로 변환
  if(cm1<5)
  {
    digitalWrite(RED1,HIGH); // RED1 On
    Serial.println("Sensor1 Too Close"); // 경고 메시지
  }
  else digitalWrite(RED1,LOW); // RED1 Off  
  
  // 초음파 센서 (2번)
  digitalWrite(6,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(6,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(6,LOW);    // Trig 신호 off
  duration2 = pulseIn(7, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm2 = microsecondsToCentimeters(duration2);  // 거리(cm)로 변환
  if(cm2<5)
  {
    digitalWrite(RED2,HIGH); // RED2 On
    Serial.println("Sensor2 Too Close"); // 경고 메시지
  }
  else digitalWrite(RED2,LOW); // RED2 Off
  
  // 초음파 센서 (3번)
  digitalWrite(8,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(8,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(8,LOW);    // Trig 신호 off  
  duration3 = pulseIn(9, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm3 = microsecondsToCentimeters(duration3);  // 거리(cm)로 변환
  if(cm3<5)
  {
    digitalWrite(RED3,HIGH); // RED3 On
    Serial.println("Sensor3 Too Close"); // 경고 메시지
  }
  else digitalWrite(RED3,LOW); // RED3 Off
  
  
  Serial.print("Sensor1 : ");
  Serial.print(cm1);
  Serial.println("cm");

  Serial.print("Sensor2 : ");
  Serial.print(cm2);
  Serial.println("cm");

  Serial.print("Sensor3 : ");
  Serial.print(cm3);
  Serial.println("cm");

  Serial.println("");

  delay(300);  // 0.3초 대기 후 다시 측정
}

int microsecondsToCentimeters(int microseconds)
{
  return microseconds/29/2;
}
