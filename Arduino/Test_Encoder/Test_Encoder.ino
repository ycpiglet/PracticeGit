#define GA 2
#define GB 3

int a;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(GA,INPUT);
  pinMode(GB,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(!digitalRead(GA)){
    if(!digitalRead(GB)){
      a--;
    }
    else{
      a++;
    }
    delay(70);
    Serial.println(a/5);
  }
}
