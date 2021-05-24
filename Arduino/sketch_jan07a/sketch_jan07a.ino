void setup() {
  // put your setup code here, to run once:
 
 
}

void loop() {
  // put your main code here, to run repeatedly:


   Serial.begin (9600);

  int sum;
  sum=add(1,2);

  Serial.print(sum);

} 

int add(int a, int b)
{
  int c;
  c=a+b;
  return c;
}
