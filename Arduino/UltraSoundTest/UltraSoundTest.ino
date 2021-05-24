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
  int duration, cm;

  digitalWrite(2,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(2,LOW);    // Trig 신호 off

  duration = pulseIn(3, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  cm = microsecondsToCentimeters(duration);  // 거리(cm)로 변환

  Serial.print(cm);
  Serial.println("cm");

  delay(300);  // 0.3초 대기 후 다시 측정
}

int microsecondsToCentimeters(int microseconds)
{
  return microseconds/29/2;
}
