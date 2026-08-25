// C++ code
//

const int led1 = 4;

const int led2 = 5;

const int echoPin = 2;

const int trigPin = 3;

const int buzzerPin = 6;

const int nThreshold = 30;

unsigned long nDuration;

float nDistance;


void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  digitalWrite(trigPin, LOW);
  
  Serial.begin(9600);
  Serial.println("iniciando detector ultrassonico...");
  
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  nDuration = pulseIn(echoPin, HIGH, 30000);
  
  if (nDuration == 0)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2,LOW);
    noTone(buzzerPin);
    
    Serial.println("Sem leitura valida.");
    delay(200);
    
    return;
  }
  
  nDistance = nDuration * 0.0343 / 2;
  
  Serial.println("Distancia: ");
  Serial.println(nDistance, 1);
  Serial.println(" cm");
  
  if (nDistance < nThreshold)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    tone(buzzerPin, 2000);
    delay(400);
    noTone(buzzerPin);
    digitalWrite(led2, LOW);
    delay(300);
  }
  
  else
  {
    digitalWrite(led2, LOW);
    noTone(buzzerPin);
    digitalWrite(led1, HIGH);
    delay(400);
    digitalWrite(led1, LOW);
    delay(300);
  }
  
  
}
