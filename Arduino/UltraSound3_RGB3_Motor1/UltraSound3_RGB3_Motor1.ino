  int Motor1_1 = 9;
  int Motor1_2 = 10;
  int RED1 = 11;
  int RED2 = 12;
  int RED3 = 13;

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);  // 초음파 센서 1번 Trig 핀
  pinMode(3,INPUT);   // 초음파 센서 1번 센서 Echo 핀
  pinMode(4,OUTPUT);  // 초음파 센서 2번 Trig 핀
  pinMode(5,INPUT);   // 초음파 센서 2번 Echo 핀
  pinMode(6,OUTPUT);  // 초음파 센서 3번 Trig 핀
  pinMode(7,INPUT);   // 초음파 센서 3번 Echo 핀
  pinMode(9,OUTPUT); // DC Motor1_1 1번 핀
  pinMode(10,OUTPUT); // DC Motor1_2 2번 핀

  pinMode(11,OUTPUT);  // Red 핀
  pinMode(12,OUTPUT);  // Green 핀
  pinMode(13,OUTPUT);  // Blue 핀

  digitalWrite(2,LOW);    // Trig 신호 off
  digitalWrite(4,LOW);    // Trig 신호 off
  digitalWrite(6,LOW);    // Trig 신호 off

  digitalWrite(11,LOW);    // Blue Off
  digitalWrite(12,LOW);    // Red off
  digitalWrite(13,LOW);    // Green off
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration1, duration2, duration3;
  int cm1, cm2, cm3;
  
  // 초음파 센서 (1번)
  digitalWrite(2,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(2,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(2,LOW);    // Trig 신호 off
  duration1 = pulseIn(3, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm1 = microsecondsToCentimeters(duration1);  // 거리(cm)로 변환
  if(cm1<5)
  {
    digitalWrite(RED1,HIGH); // RED1 On
    Serial.println("Sensor1 Too Close"); // 경고 메시지
    digitalWrite(Motor1_1,HIGH);
    digitalWrite(Motor1_2,LOW);
  }
  else
  {
    digitalWrite(RED1,LOW); // RED1 Off
    digitalWrite(Motor1_1,LOW);
    digitalWrite(Motor1_2,HIGH);
  }
  
  
  
  // 초음파 센서 (2번)
  digitalWrite(4,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(4,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(4,LOW);    // Trig 신호 off
  duration2 = pulseIn(5, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm2 = microsecondsToCentimeters(duration2);  // 거리(cm)로 변환
  if(cm2<5)
  {
    digitalWrite(RED2,HIGH); // RED2 On
    Serial.println("Sensor2 Too Close"); // 경고 메시지
  }
  else
  {
    digitalWrite(RED2,LOW); // RED2 Off
  }
  
  // 초음파 센서 (3번)
  digitalWrite(6,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(6,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(6,LOW);    // Trig 신호 off  
  duration3 = pulseIn(7, HIGH);  // Echo pin: HIGH->Low 간격을 측정
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
