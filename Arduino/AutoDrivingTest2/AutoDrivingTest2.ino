///////////////////////////////////////////////
//  하이로보 현장실습 과제                       //
//  자율주행 미로 탈출 RC 카 제작                //
//  초음파 센서 3개, RGB LED 3개, DC 모터 2개   //
/////////////////////////////////////////////

  // 인터럽트 사용할 것인가?
  // 굴러가다가, 너무 근접하면 Stop, Led Red ON, 후진 후 방향 전환
  // 만약 왼쪽이 막혔으면 3cm 후진 후, 우회전 6cm, 직진
  // 또는 우측 바퀴만 역회전 후, 좌측 바퀴 정회전

#include <NewPing.h>
#define MAX_DISTANCE 200
#define MOTOR_L1 10 // 왼쪽 모터 정회전
#define MOTOR_L2 11 // 왼쪽 모터 역회전
#define MOTOR_R1 12 // 오른쪽 모터 정회전
#define MOTOR_R2 13 // 오른쪽 모터 역회전
#define RED_1 3 // RGB LED 1번의 RED
#define RED_2 5 // RGB LED 2번의 RED
#define RED_3 7 // RGB LED 3번의 RED
#define ULTRA_1T = 0; // 아날로그 1번 초음파 센서 Trigger
#define ULTRA_1E = 1; // 아날로그 1번 초음파 센서 Echo
#define ULTRA_2T = 2; // 아날로그 2번 초음파 센서 Trigger
#define ULTRA_2E = 3; // 아날로그 2번 초음파 센서 Echo
#define ULTRA_3T = 4; // 아날로그 3번 초음파 센서 Trigger
#define ULTRA_3E = 5; // 아날로그 3번 초음파 센서 Echo
#define Duration_Front, Duration_Left, Duration_Right;
#define Distance_Front, Distance_Left, Distance_Right;

unsigned long pingTimer[3]; // When each pings.
unsigned int cm[3]; // Store ping distances.
uint8_t currentSensor = 0; // Which sensor is active.

//sonar(TrigPin, EchoPin, MaxDistance);
NewPing sonar[3] {
  NewPing(0,1,MAX_DISTANCE);
  NewPing(2,3,MAX_DISTANCE);
  NewPing(4,5,MAX_DISTANCE);
}

// 1번(좌측), 2번(우측), 3번(정면)
// RGB LED(Digital Pin 3,5,7), DC Motor(Digital Pin 10~13), UltraSound(Analog Pin 0~5)

/* 초기화 부분*/
void setup() {
  Serial.begin(9600); //시리얼 모니터 확인용 : Baudrate=9600
  Digital_Pin_Init(); //Digita Pin 활성화
  Device_Init(); //각 센서 초기화
}

/* 반복 실행 부분*/
void loop() {
  //Motor_Init();
  Ultra_Init();
  Distance_Init();
  Serial_Monitor(); // 시리얼 모니터 확인
  delay(300); // 0.3초 대기 후 다시 측정
}

//////////////////////////////////////
/////// 사용자 임의 함수 정의 //////////
////////////////////////////////////

int microsecondsToCentimeters(int microseconds) 
{
  // 측정거리(Distance)를 cm로 변환하는 함수
  return microseconds/29/2;
}

void Digital_Pin_Init(void) 
{
  // Digital Pin 활성화
  pinMode(Ultra_1T,OUTPUT);  // 1번 초음파 센서 Trig 핀
  pinMode(Ultra_1E,INPUT);   // 1번 초음파 센서 Echo 핀
  pinMode(Ultra_2T,OUTPUT);  // 2번 초음파 센서 Trig 핀
  pinMode(Ultra_2E,INPUT);   // 2번 초음파 센서 Echo 핀
  pinMode(Ultra_3T,OUTPUT);  // 3번 초음파 센서 Trig 핀
  pinMode(Ultra_3E,INPUT);   // 3번 초음파 센서 Echo 핀
  //pinMode(Motor_L1,OUTPUT); // 왼쪽 DC Motor 정회전 핀
  //pinMode(Motor_L2,OUTPUT); // 왼쪽 DC Motor 역회전 핀
  //pinMode(Motor_R1,OUTPUT); // 오른쪽 DC Motor 정회전 핀
  //pinMode(Motor_R2,OUTPUT); // 오른쪽 DC Motor 역회전 핀
  pinMode(RED1,OUTPUT);  // Red1 핀
  pinMode(RED2,OUTPUT);  // Red2 핀
  pinMode(RED3,OUTPUT);  // Red3 핀  
}

void Device_Init(void) 
{
  // Device 초기화
  digitalWrite(Ultra_1T,LOW);    // 1번 초음파 센서 Trig 신호 off
  digitalWrite(Ultra_2T,LOW);    // 2번 초음파 센서 Trig 신호 off
  digitalWrite(Ultra_3T,LOW);    // 3번 초음파 센서 Trig 신호 off
  digitalWrite(RED1,LOW);    // RGB LED 1번의 RED Off
  digitalWrite(RED2,LOW);    // RGB LED 2번의 RED off
  digitalWrite(RED3,LOW);    // RGB LED 3번의 RED off
  digitalWrite(Motor_L1,LOW); // Motor L1 off
  digitalWrite(Motor_L2,LOW); // Motor L2 off
  digitalWrite(Motor_R1,LOW); // Motor R1 off
  digitalWrite(Motor_R2,LOW); // Motor R2 off
}

void Serial_Monitor(void) 
{
  // 시리얼 모니터 확인
  Serial.print("좌측 : ");
  Serial.print(sonar[0].ping_cm());
  Serial.println("cm");
  Serial.print("우측 : ");
  Serial.print(sonar[1].ping_cm());
  Serial.println("cm");
  Serial.print("정면 : ");
  Serial.print(sonar[2].ping_cm());
  Serial.println("cm");
  Serial.println("");  
}

void Motor_Init() 
{
  // 모터 전진
  digitalWrite(Motor_L1,HIGH);
  digitalWrite(Motor_L2,LOW);
  digitalWrite(Motor_R1,HIGH);
  digitalWrite(Motor_R2,LOW); 
}

void Ultra_Init(void)
{
  // 초음파 센서로 거리 측정
  digitalWrite(Ultra_1T,HIGH);   // 센서에 Trig 신호 입력
  digitalWrite(Ultra_2T,HIGH);   // 센서에 Trig 신호 입력
  digitalWrite(Ultra_3T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(Ultra_1T,LOW);    // Trig 신호 off
  digitalWrite(Ultra_2T,LOW);    // Trig 신호 off
  digitalWrite(Ultra_3T,LOW);    // Trig 신호 off
  Duration_Left = pulseIn(Ultra_1E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Duration_Right = pulseIn(Ultra_2E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Duration_Front = pulseIn(Ultra_3E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Left = microsecondsToCentimeters(Duration_Left);  // 거리(cm)로 변환, 왼쪽 거리 측정
  Distance_Right = microsecondsToCentimeters(Duration_Right);  // 거리(cm)로 변환, 오른쪽 거리 측정
  Distance_Front = microsecondsToCentimeters(Duration_Front);  // 거리(cm)로 변환, 정면 거리 측정
}

void Distance_Init(void)
{
  // 장애물 발견 시 경고 메시지 & LED RED ON
  if(Distance_Left < 3)  // 왼쪽 거리가 너무 가까우면
  {
    digitalWrite(RED1,HIGH); // RED1 On
    Serial.println("LEFT <Too Close>"); // 경고 메시지
    digitalWrite(Motor_L1,HIGH);
    digitalWrite(Motor_L2,LOW);
  }
  else  
  {
    digitalWrite(RED1,LOW); // RED1 Off
    digitalWrite(Motor_L1,LOW);
    digitalWrite(Motor_L2,HIGH);
  }
  if(Distance_Right < 3)  // 왼쪽 거리가 너무 가까우면
  {  
    digitalWrite(RED2,HIGH); // RED1 On
    Serial.println("RIGHT <Too Close>"); // 경고 메시지
    digitalWrite(Motor_R1,HIGH);
    digitalWrite(Motor_R2,LOW);
  }
  else 
  {
    digitalWrite(RED1,LOW); // RED1 Off
    digitalWrite(Motor_L1,LOW);
    digitalWrite(Motor_L2,HIGH);
  }
  if(Distance_Front < 3)  // 정면 거리가 너무 가까우면
  {
    digitalWrite(RED3,HIGH); // RED1 On
    Serial.println("FRONT <Too Close>"); // 경고 메시지
    digitalWrite(Motor_L1,LOW);
    digitalWrite(Motor_L2,HIGH);
    digitalWrite(Motor_R1,LOW);
    digitalWrite(Motor_R2,HIGH);
  }
  else
  {
    digitalWrite(RED3,LOW); // RED1 Off
  }
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
