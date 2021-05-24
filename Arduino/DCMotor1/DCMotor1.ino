  int Motor1_1 = 9;
  int Motor1_2 = 10;
  int RED1 = 11;
  int RED2 = 12;
  int RED3 = 13;

  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

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
  //정회전
  digitalWrite(Motor1_1,HIGH);
  digitalWrite(Motor1_2,LOW);
  delay(300);
  Serial.println("CW");
  //역회전
  digitalWrite(Motor1_1,LOW);
  digitalWrite(Motor1_2,HIGH);
  
  Serial.println("CCW");

  delay(300);  // 0.3초 대기 후 다시 측정
}

int microsecondsToCentimeters(int microseconds)
{
  return microseconds/29/2;
}
