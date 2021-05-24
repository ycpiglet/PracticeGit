////////////////////////////////////////////////
//  하이로보 현장실습 과제                       //
//  자율주행 미로 탈출 RC 카 제작                //
//  초음파 센서 3개, RGB LED 3개, DC 모터 2개   //
//////////////////////////////////////////////

/* 각 pin을 전역변수로 설정 */
// 1번(좌측), 2번(우측), 3번(정면)
  int Motor_L1 = 9; // 왼쪽 모터 정회전
  int Motor_L2 = 10; // 왼쪽 모터 역회전
  int Motor_R1 = 0; // 오른쪽 모터 정회전
  int Motor_R2 = 0; // 오른쪽 모터 역회전
  int RED1 = 11; // RGB LED 1번의 RED
  int RED2 = 12; // RGB LED 2번의 RED
  int RED3 = 13; // RGB LED 3번의 RED
  int Ultra_1T = 2; // 1번 초음파 센서 Trigger
  int Ultra_1E = 3; // 1번 초음파 센서 Echo
  int Ultra_2T = 4; // 2번 초음파 센서 Trigger
  int Ultra_2E = 5; // 2번 초음파 센서 Echo
  int Ultra_3T = 6; // 3번 초음파 센서 Trigger
  int Ultra_3E = 7; // 3번 초음파 센서 Echo

/* 초기화 부분 */
void setup() {
  Serial.begin(9600); //시리얼 모니터 확인용 : Baudrate=9600
  Digital_Pin_Init(); //Digita Pin 활성화
  Device_Init(); //각 센서 초기화
} // Setup문 끝

/* 반복 실행 부분*/
void loop() {
  // put your main code here, to run repeatedly:
  int Duration_Front, Duration_Left, Duration_Right;
  int Distance_Front, Distance_Left, Distance_Right;

  // 인터럽트 사용할 것인가?
  // 굴러가다가, 너무 근접하면 Stop, Led Red ON, 후진 후 방향 전환
  // 만약 왼쪽이 막혔으면 3cm 후진 후, 우회전 6cm, 직진
  // 또는 우측 바퀴만 역회전 후, 좌측 바퀴 정회전
  
  // 1번 초음파 센서 (좌측)
  digitalWrite(Ultra_1T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(Ultra_1T,LOW);    // Trig 신호 off
  Duration_Left = pulseIn(Ultra_1E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Left = microsecondsToCentimeters(Duration_Left);  // 거리(cm)로 변환
  if(Distance_Left < 5)  {
    digitalWrite(RED1,HIGH); // RED1 On
    Serial.println("LEFT <Too Close>"); // 경고 메시지
    digitalWrite(Motor_L1,HIGH);
    digitalWrite(Motor_L2,LOW);
  }
  else  {
    digitalWrite(RED1,LOW); // RED1 Off
    digitalWrite(Motor_L1,LOW);
    digitalWrite(Motor_L2,HIGH);
  }
  
  // 2번 초음파 센서 (우측)
  digitalWrite(Ultra_2T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(Ultra_2T,LOW);    // Trig 신호 off
  Duration_Right = pulseIn(Ultra_2E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Right = microsecondsToCentimeters(Duration_Right);  // 거리(cm)로 변환
  if(Distance_Right < 5)  {
    digitalWrite(RED2,HIGH); // RED2 On
    Serial.println("RIGHT <Too Close>"); // 경고 메시지
  }
  else  {
    digitalWrite(RED2,LOW); // RED2 Off
  }
  
  // 3번 초음파 센서 (정면)
  digitalWrite(Ultra_3T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(Ultra_3T,LOW);    // Trig 신호 off  
  Duration_Front = pulseIn(Ultra_3E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Front = microsecondsToCentimeters(Duration_Front);  // 거리(cm)로 변환
  if(Distance_Front < 5)  {
    digitalWrite(RED3,HIGH); // RED3 On
    Serial.println("FRONT <Too Close>"); // 경고 메시지
  }
  else {
    digitalWrite(RED3,LOW); // RED3 Off
  }
  
  // 시리얼 모니터 확인
  Serial.print("좌측 : ");
  Serial.print(Distance_Left);
  Serial.println("cm");
  Serial.print("우측 : ");
  Serial.print(Distance_Right);
  Serial.println("cm");
  Serial.print("정면 : ");
  Serial.print(Distance_Front);
  Serial.println("cm \n");
  
  // 0.3초 대기 후 다시 측정
  delay(300);  
} // loop문 끝


/* 사용자 임의 함수 정의 */
int microsecondsToCentimeters(int microseconds) // 측정거리를 cm로 변환
{
  return microseconds/29/2;
}

void Digital_Pin_Init(void) // Digital Pin 활성화
{
  pinMode(Ultra_1T,OUTPUT);  // 1번 초음파 센서 Trig 핀
  pinMode(Ultra_1E,INPUT);   // 1번 초음파 센서 센서 Echo 핀
  pinMode(Ultra_2T,OUTPUT);  // 2번 초음파 센서 Trig 핀
  pinMode(Ultra_2E,INPUT);   // 2번 초음파 센서 Echo 핀
  pinMode(Ultra_3T,OUTPUT);  // 3번 초음파 센서 Trig 핀
  pinMode(Ultra_3E,INPUT);   // 3번 초음파 센서 Echo 핀
  pinMode(Motor_L1,OUTPUT); // 왼쪽 DC Motor 정회전 핀
  pinMode(Motor_L2,OUTPUT); // 왼쪽 DC Motor 역회전 핀
  //pinMode(Motor_R1,OUTPUT); // 오른쪽 DC Motor 정회전 핀
  //pinMode(Motor_R2,OUTPUT); // 오른쪽 DC Motor 역회전 핀
  pinMode(RED1,OUTPUT);  // Red1 핀
  pinMode(RED2,OUTPUT);  // Red2 핀
  pinMode(RED3,OUTPUT);  // Red3 핀  
}

void Device_Init(void) // Device 초기화
{
  digitalWrite(Ultra_1T,LOW);    // 1번 초음파 센서 Trig 신호 off
  digitalWrite(Ultra_2T,LOW);    // 2번 초음파 센서 Trig 신호 off
  digitalWrite(Ultra_3T,LOW);    // 3번 초음파 센서 Trig 신호 off
  digitalWrite(RED1,LOW);    // RGB LED 1번의 RED Off
  digitalWrite(RED2,LOW);    // RGB LED 2번의 RED off
  digitalWrite(RED3,LOW);    // RGB LED 3번의 RED off
}

/* void Distance(int Ultra_T)
{
  int Ultra_E;
  Ultra_E = Ultra+1;
  // 1번 초음파 센서 (좌측)
  digitalWrite(Ultra_T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지
  digitalWrite(Ultra_T,LOW);    // Trig 신호 off
  Duration_Left = pulseIn(Ultra_E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Left = microsecondsToCentimeters(Duration_Left);  // 거리(cm)로 변환
  if(Distance_Left < 5)  {
    digitalWrite(RED1,HIGH); // RED1 On
    Serial.println("LEFT <Too Close>"); // 경고 메시지
    digitalWrite(Motor_L1,HIGH);
    digitalWrite(Motor_L2,LOW);
  }
  else  {
    digitalWrite(RED1,LOW); // RED1 Off
    digitalWrite(Motor_L1,LOW);
    digitalWrite(Motor_L2,HIGH);
  }
} */
