///////////////////////////////////////////////
//  하이로보 현장실습 과제                       //
//  자율주행 미로 탈출 RC 카 제작                //
//  초음파 센서 3개, RGB LED 3개, DC 모터 2개   //
/////////////////////////////////////////////

  // 인터럽트 사용할 것인가?
  // 굴러가다가, 너무 근접하면 Stop, Led Red ON, 후진 후 방향 전환
  // 만약 왼쪽이 막혔으면 3cm 후진 후, 우회전 6cm, 직진
  // 또는 우측 바퀴만 역회전 후, 좌측 바퀴 정회전

#define MAX_DISTANCE 200
#define MOTOR_L1 10 // 왼쪽 모터 정회전
#define MOTOR_L2 11 // 왼쪽 모터 역회전
#define MOTOR_R1 12 // 오른쪽 모터 정회전
#define MOTOR_R2 13 // 오른쪽 모터 역회전
#define RED_1 14 // (A0) RGB LED 1번의 RED
#define RED_2 15 // (A1) RGB LED 2번의 RED
#define RED_3 16 // (A2) RGB LED 3번의 RED
#define ULTRA_1T 4 // 1번 초음파 센서 Trigger
#define ULTRA_1E 5 // 1번 초음파 센서 Echo
#define ULTRA_2T 6 // 2번 초음파 센서 Trigger
#define ULTRA_2E 7 // 2번 초음파 센서 Echo
#define ULTRA_3T 8 // 3번 초음파 센서 Trigger
#define ULTRA_3E 9 // 3번 초음파 센서 Echo

// 1번(좌측), 2번(우측), 3번(정면)
// RGB LED(Digital Pin 3,5,7), DC Motor(Digital Pin 10~13), UltraSound(Analog Pin 0~5)

int Duration_Front, Duration_Left, Duration_Right;
int Distance_Front, Distance_Left, Distance_Right;

/* 초기화 부분*/
void setup() {
  Serial.begin(9600); //시리얼 모니터 확인용 : Baudrate=9600
  Digital_Pin_Init(); //Digita Pin 활성화
  Device_Init(); //각 센서 초기화
  Motor_Forward();
}

/* 반복 실행 부분*/
void loop() {
  // 초음파 센서로 거리 측정
  digitalWrite(ULTRA_1T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_1T,LOW);    // Trig 신호 off
  Duration_Left = pulseIn(ULTRA_1E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Left = microsecondsToCentimeters(Duration_Left);  // 거리(cm)로 변환, 왼쪽 거리 측정
  if(Distance_Left < 3)  // 왼쪽 거리가 너무 가까우면
  {
    digitalWrite(RED_1,HIGH); // RED1 On
    Serial.println("LEFT <Too Close>"); // 경고 메시지
    digitalWrite(MOTOR_L1,HIGH);
    digitalWrite(MOTOR_L2,LOW);
  }
  else  
  {
    digitalWrite(RED_1,LOW); // RED1 Off
    digitalWrite(MOTOR_L1,LOW);
    digitalWrite(MOTOR_L2,HIGH);
  }
  
  digitalWrite(ULTRA_2T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_2T,LOW);    // Trig 신호 off
  Duration_Right = pulseIn(ULTRA_2E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Right = microsecondsToCentimeters(Duration_Right);  // 거리(cm)로 변환, 오른쪽 거리 측정
  if(Distance_Right < 3)  // 왼쪽 거리가 너무 가까우면
  {  
    digitalWrite(RED_2,HIGH); // RED1 On
    Serial.println("RIGHT <Too Close>"); // 경고 메시지
    digitalWrite(MOTOR_R1,HIGH);
    digitalWrite(MOTOR_R2,LOW);
  }
  else 
  {
    digitalWrite(RED_2,LOW); // RED1 Off
    digitalWrite(MOTOR_R1,LOW);
    digitalWrite(MOTOR_R2,HIGH);
  }
  
  digitalWrite(ULTRA_3T,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_3T,LOW);    // Trig 신호 off
  Duration_Front = pulseIn(ULTRA_3E, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Front = microsecondsToCentimeters(Duration_Front);  // 거리(cm)로 변환, 정면 거리 측정
  if(Distance_Front < 3)  // 정면 거리가 너무 가까우면
  {
    digitalWrite(RED_3,HIGH); // RED1 On
    Serial.println("FRONT <Too Close>"); // 경고 메시지
    //digitalWrite(MOTOR_L1,LOW);
    //digitalWrite(MOTOR_L2,HIGH);
    //digitalWrite(MOTOR_R1,LOW);
    //digitalWrite(MOTOR_R2,HIGH);
  }
  else
  {
    digitalWrite(RED_3,LOW); // RED1 Off
  }
  
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
  pinMode(ULTRA_1T,OUTPUT);  // 1번 초음파 센서 Trig 핀
  pinMode(ULTRA_1E,INPUT);   // 1번 초음파 센서 Echo 핀
  pinMode(ULTRA_2T,OUTPUT);  // 2번 초음파 센서 Trig 핀
  pinMode(ULTRA_2E,INPUT);   // 2번 초음파 센서 Echo 핀
  pinMode(ULTRA_3T,OUTPUT);  // 3번 초음파 센서 Trig 핀
  pinMode(ULTRA_3E,INPUT);   // 3번 초음파 센서 Echo 핀
  pinMode(MOTOR_L1,OUTPUT); // 왼쪽 DC Motor 정회전 핀
  pinMode(MOTOR_L2,OUTPUT); // 왼쪽 DC Motor 역회전 핀
  pinMode(MOTOR_R1,OUTPUT); // 오른쪽 DC Motor 정회전 핀
  pinMode(MOTOR_R2,OUTPUT); // 오른쪽 DC Motor 역회전 핀
  pinMode(RED_1,OUTPUT);  // Red1 핀
  pinMode(RED_2,OUTPUT);  // Red2 핀
  pinMode(RED_3,OUTPUT);  // Red3 핀  
}

void Device_Init(void) 
{
  // Device 초기화
  digitalWrite(ULTRA_1T,LOW);    // 1번 초음파 센서 Trig 신호 off
  digitalWrite(ULTRA_2T,LOW);    // 2번 초음파 센서 Trig 신호 off
  digitalWrite(ULTRA_3T,LOW);    // 3번 초음파 센서 Trig 신호 off
  digitalWrite(RED_1,LOW);    // RGB LED 1번의 RED Off
  digitalWrite(RED_2,LOW);    // RGB LED 2번의 RED off
  digitalWrite(RED_3,LOW);    // RGB LED 3번의 RED off
  digitalWrite(MOTOR_L1,LOW); // Motor L1 off
  digitalWrite(MOTOR_L2,LOW); // Motor L2 off
  digitalWrite(MOTOR_R1,LOW); // Motor R1 off
  digitalWrite(MOTOR_R2,LOW); // Motor R2 off
}

void Serial_Monitor(void) 
{
  // 시리얼 모니터 확인
  Serial.print("좌측 : ");
  Serial.print(Distance_Left);
  Serial.println("cm");
  Serial.print("우측 : ");
  Serial.print(Distance_Right);
  Serial.println("cm");
  Serial.print("정면 : ");
  Serial.print(Distance_Front);
  Serial.println("cm");
  Serial.println("");
}

void Motor_Forward() 
{
  // 모터 전진
  digitalWrite(MOTOR_L1,LOW);
  digitalWrite(MOTOR_L2,HIGH);
  digitalWrite(MOTOR_R1,HIGH);
  digitalWrite(MOTOR_R2,LOW); 
}

void Motor_Backward() 
{
  // 모터 후진
  digitalWrite(MOTOR_L1,HIGH);
  digitalWrite(MOTOR_L2,LOW);
  digitalWrite(MOTOR_R1,LOW);
  digitalWrite(MOTOR_R2,HIGH); 
}
