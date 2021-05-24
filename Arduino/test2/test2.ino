/////////////////////////////////////////////////
//  하이로보 현장실습 과제                       //
//  자율주행 미로 탈출 RC 카 제작                //
//  초음파 센서 3개, RGB LED 3개, DC 모터 2개   //
//////////////////////////////////////////////

#define ULTRA_FRONT_TRIG 4 // 3번 초음파 센서 Trigger
#define ULTRA_FRONT_ECHO 5 // 3번 초음파 센서 Echo
#define ULTRA_RIGHT_TRIG 6 // 2번 초음파 센서 Trigger
#define ULTRA_RIGHT_ECHO 7 // 2번 초음파 센서 Echo
#define ULTRA_LEFT_TRIG 8 // 1번 초음파 센서 Trigger
#define ULTRA_LEFT_ECHO 9 // 1번 초음파 센서 Echo
#define MOTOR_LEFT_CW 10 // 왼쪽 모터 역회전
#define MOTOR_LEFT_CCW 11 // 왼쪽 모터 정회전
#define MOTOR_RIGHT_CW 12 // 오른쪽 모터 정회전
#define MOTOR_RIGHT_CCW 13 // 오른쪽 모터 역회전
#define RED_FRONT 14 // (A0) RGB LED 3번의 RED
#define RED_RIGHT 15 // (A1) RGB LED 2번의 RED
#define RED_LEFT 16 // (A2) RGB LED 1번의 RED

// 1번(좌측), 2번(우측), 3번(정면)
// RGB LED(Analog Pin 0~3), DC Motor(Digital Pin 10~13), UltraSound(Digital Pin 4~9)

int Duration_Front, Duration_Left, Duration_Right;
int Distance_Front, Distance_Left, Distance_Right;
int CASE, Front, Left, Right;

/* 초기화 부분*/
void setup() {
  Serial.begin(9600); //시리얼 모니터 확인용 : Baudrate=9600
  Pin_Init(); //Digita Pin 활성화
  Device_Init(); //각 센서 초기화
}

/* 반복 실행 부분*/
void loop() {
  // 초음파 센서로 거리 측정 (좌측)
  digitalWrite(ULTRA_LEFT_TRIG,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_LEFT_TRIG,LOW);    // Trig 신호 off
  Duration_Left = pulseIn(ULTRA_LEFT_ECHO, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Left = microsecondsToCentimeters(Duration_Left);  // 거리(cm)로 변환, 왼쪽 거리 측정
  if(Distance_Left < 5)  // 왼쪽 거리가 너무 가까우면
  {
    digitalWrite(RED_LEFT,HIGH); // RED1 On
    //Serial.println("LEFT <Too Close>"); // 경고 메시지
    Left = 2;
  }
  /*else if(Distance_Left < 8) // 적정거리 유지
  {
    Left = 2;
  }*/
  else  
  {
    digitalWrite(RED_LEFT,LOW); // RED1 Off
    Left = 0;
  }
  // 초음파 센서로 거리 측정 (우측)
  digitalWrite(ULTRA_RIGHT_TRIG,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_RIGHT_TRIG,LOW);    // Trig 신호 off
  Duration_Right = pulseIn(ULTRA_RIGHT_ECHO, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Right = microsecondsToCentimeters(Duration_Right);  // 거리(cm)로 변환, 오른쪽 거리 측정
  if(Distance_Right < 5)  // 왼쪽 거리가 너무 가까우면
  {  
    digitalWrite(RED_RIGHT,HIGH); // RED2 On
    //Serial.println("RIGHT <Too Close>"); // 경고 메시지
    Right = 1;
  }
  else 
  {
    digitalWrite(RED_RIGHT,LOW); // RED2 Off
    Right = 0;
  }
  // 초음파 센서로 거리 측정 (정면)
  digitalWrite(ULTRA_FRONT_TRIG,HIGH);   // 센서에 Trig 신호 입력
  delayMicroseconds(10);  // 10us 정도 유지 (고정)
  digitalWrite(ULTRA_FRONT_TRIG,LOW);    // Trig 신호 off
  Duration_Front = pulseIn(ULTRA_FRONT_ECHO, HIGH);  // Echo pin: HIGH->Low 간격을 측정
  Distance_Front = microsecondsToCentimeters(Duration_Front);  // 거리(cm)로 변환, 정면 거리 측정
  if(Distance_Front < 5)  // 정면 거리가 너무 가까우면
  {
    digitalWrite(RED_FRONT,HIGH); // RED3 On
    //Serial.println("FRONT <Too Close>"); // 경고 메시지
    Front = 4;
  }
  else
  {
    digitalWrite(RED_FRONT,LOW); // RED3 Off
    Front = 0;
  }

  CASE = Front + Left + Right;
  switch (CASE) // 경우의 수를 판단한다
  {
    case 0 :  Serial.println("CASE 0 : 장애물이 없습니다!!");
              Motor_Forward(); // 직진
              break;
             
    case 1 :  Serial.println("CASE 1 : '오른쪽'만 막혔습니다!");
              Motor_Right(); // 직진
              break;
             
    case 2 :  //delay(500);
              Serial.println("CASE 2 : '왼쪽'만 막혔습니다!");
              Motor_Left(); // 우회전
              break;
             
    case 3 :  Serial.println("CASE 3 : '양 옆'이 모두 막혔습니다!");
              Motor_Forward(); // 직진
              break;
             
    case 4 :  //delay(500);
              Serial.println("CASE 4 : '정면'만 막혔습니다!");
              Motor_Right(); // 우회전
              break;
             
    case 5 :  //delay(500);
              Serial.println("CASE 5 : '정면'과 '오른쪽'이 막혔습니다!");
              Motor_Left(); // 좌회전
              break;    
                                    
    case 6 :  //delay(500);
              Serial.println("CASE 6 : '정면'과 '왼쪽'이 막혔습니다!");
              Motor_Right(); // 우회전
              break;
             
    case 7 :  //delay(500);
              Serial.println("CASE 7 : '사방'이 '모두' 막혔습니다!");
              Motor_Turn(); // 180도 회전
              break;
  }
  
  Serial_Monitor(); // 시리얼 모니터 확인
  delay(200); // 0.2초 대기 후 다시 측정
}

//////////////////////////////////////
/////// 사용자 임의 함수 정의 //////////
////////////////////////////////////

int microsecondsToCentimeters(int microseconds) 
{
  // 측정거리(Distance)를 cm로 변환하는 함수
  return microseconds/29/2;
}

void Pin_Init(void) 
{
  // Digital Pin 활성화
  pinMode(ULTRA_LEFT_TRIG,OUTPUT);  // 1번 초음파 센서 Trig 핀
  pinMode(ULTRA_LEFT_ECHO,INPUT);   // 1번 초음파 센서 Echo 핀
  pinMode(ULTRA_RIGHT_TRIG,OUTPUT);  // 2번 초음파 센서 Trig 핀
  pinMode(ULTRA_RIGHT_ECHO,INPUT);   // 2번 초음파 센서 Echo 핀
  pinMode(ULTRA_FRONT_TRIG,OUTPUT);  // 3번 초음파 센서 Trig 핀
  pinMode(ULTRA_FRONT_ECHO,INPUT);   // 3번 초음파 센서 Echo 핀
  pinMode(MOTOR_LEFT_CW,OUTPUT); // 왼쪽 DC Motor 정회전 핀
  pinMode(MOTOR_LEFT_CCW,OUTPUT); // 왼쪽 DC Motor 역회전 핀
  pinMode(MOTOR_RIGHT_CW,OUTPUT); // 오른쪽 DC Motor 정회전 핀
  pinMode(MOTOR_RIGHT_CCW,OUTPUT); // 오른쪽 DC Motor 역회전 핀
  pinMode(RED_LEFT,OUTPUT);  // Red1 핀
  pinMode(RED_RIGHT,OUTPUT);  // Red2 핀
  pinMode(RED_FRONT,OUTPUT);  // Red3 핀  
}

void Device_Init(void) 
{
  // Device 초기화
  digitalWrite(ULTRA_LEFT_TRIG,LOW);    // 1번 초음파 센서 Trig 신호 off
  digitalWrite(ULTRA_RIGHT_TRIG,LOW);    // 2번 초음파 센서 Trig 신호 off
  digitalWrite(ULTRA_FRONT_TRIG,LOW);    // 3번 초음파 센서 Trig 신호 off
  digitalWrite(RED_LEFT,LOW);    // RGB LED 1번의 RED Off
  digitalWrite(RED_RIGHT,LOW);    // RGB LED 2번의 RED off
  digitalWrite(RED_FRONT,LOW);    // RGB LED 3번의 RED off
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
}

void Serial_Monitor(void) 
{
  // 시리얼 모니터 확인
  Serial.println("<거리 측정 결과>");
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
  Serial.println("'전진'합니다!");
  delay(500);
  digitalWrite(MOTOR_LEFT_CW,LOW);
  digitalWrite(MOTOR_LEFT_CCW,HIGH);
  digitalWrite(MOTOR_RIGHT_CW,HIGH);
  digitalWrite(MOTOR_RIGHT_CCW,LOW); 
}

void Motor_Backward() 
{
  // 모터 후진
  Serial.println("'후진'합니다!");
  delay(500);
  digitalWrite(MOTOR_LEFT_CW,HIGH);
  digitalWrite(MOTOR_LEFT_CCW,LOW);
  digitalWrite(MOTOR_RIGHT_CW,LOW);
  digitalWrite(MOTOR_RIGHT_CCW,HIGH); 
}

void Motor_Left()
{
  // 모터 좌회전 (좌측의 측정 거리가 멀면)
  Serial.println("'좌회전'합니다!");
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
  digitalWrite(MOTOR_LEFT_CCW,HIGH);
  digitalWrite(MOTOR_RIGHT_CCW,HIGH);
  delay(1000);
  //digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  //digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
}

void Motor_Right()
{
  // 모터 우회전 (우측의 측정 거리가 멀면)
  Serial.println("'우회전'합니다!");
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
  digitalWrite(MOTOR_LEFT_CW,HIGH);
  digitalWrite(MOTOR_RIGHT_CW,HIGH);
  delay(1000);
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  //digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  //digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
}

void Motor_Turn()
{
  // 모터 180도 회전
  Serial.print("'180도 회전'합니다!");
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
  digitalWrite(MOTOR_LEFT_CW,HIGH);
  digitalWrite(MOTOR_RIGHT_CW,HIGH);
  delay(2000);
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  //digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  //digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(1000);
}

void Motor_Stop()
{
  // 모터 정지 (앞이 막혔으면)
  digitalWrite(MOTOR_LEFT_CW,LOW); // Motor L1 off
  digitalWrite(MOTOR_LEFT_CCW,LOW); // Motor L2 off
  digitalWrite(MOTOR_RIGHT_CW,LOW); // Motor R1 off
  digitalWrite(MOTOR_RIGHT_CCW,LOW); // Motor R2 off
  delay(500);
}

// 경우의 수
// 각 경우마다 번호 부여
// 케이스 함수로 번호 때 구현할 내용

// 전진 - 앞이 뚫려 있을 때, 좌 우에 벽이 있을 때 (적정 거리 판단 필요)

// 정지 - 앞이 너무 가까울 때 정지 후 회전 판단, 좌 우가 너무 가까울 때

// 좌회전 - 왼쪽 측정 거리가 멀면 && 앞이 막혀 있으면 좌회전

// 우회전 - 오른쪽 측정 거리가 멀면 무조건 좌회전

// 180도 회전

// 동작 순서 : 초음파 센서로 거리 판단 -> 정지 -> 회전 판단 -> 전진
