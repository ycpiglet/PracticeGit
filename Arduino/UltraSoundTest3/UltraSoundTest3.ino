void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);  // 센서 Trig 핀
  pinMode(3,INPUT);   // 센서 Echo 핀
  pinMode(5,OUTPUT);  // 센서 Trig 핀
  pinMode(6,INPUT);   // 센서 Echo 핀
  pinMode(8,OUTPUT);  // 센서 Trig 핀
  pinMode(9,INPUT);   // 센서 Echo 핀
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration1, duration2, duration3;
  int cm1, cm2, cm3;

  digitalWrite(2,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(2,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(2,LOW);    // Trig 신호 off


  
  digitalWrite(5,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(5,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(5,LOW);    // Trig 신호 off


  digitalWrite(8,LOW);    // Trig 신호 off
  delayMicroseconds(2);  // 10us 정도 유지
  digitalWrite(8,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(8,LOW);    // Trig 신호 off

  duration1 = pulseIn(3, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  duration2 = pulseIn(6, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  duration3 = pulseIn(9, HIGH);  // Echo pin: HIGH->Low 간격을 측정

  cm1 = microsecondsToCentimeters(duration1);  // 거리(cm)로 변환
  cm2 = microsecondsToCentimeters(duration2);  // 거리(cm)로 변환
  cm3 = microsecondsToCentimeters(duration3);  // 거리(cm)로 변환

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
