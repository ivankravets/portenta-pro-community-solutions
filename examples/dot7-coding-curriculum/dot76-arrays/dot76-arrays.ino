// Global Variables
int myMax = 9;
int myArray[myMax];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  randomSeed( analogRead(A1) );  // set the random generator to A1 a random starting number
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int myLocation = random(0, myMax-1);
  myArray[myLocation] = random(0,9);
  
  for (int i=0; i < myMax; i++){
    Serial.print(myArray[i]);
    Serial.print(", ");
  }
    
  Serial.println();
  Serial.println("-----------------------------" );
  Serial.println();
  delay(2000);

}
