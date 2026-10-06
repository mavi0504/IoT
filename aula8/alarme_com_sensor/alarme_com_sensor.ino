int LDR = A0;
int LED_ALERTA = 7;
int BUZZER = 8;
int LIMITE_LUZ = 500;
void setup()
{
  Serial.begin(9600);
  pinMode(LED_ALERTA, OUTPUT);
  pinMode(BUZZER,OUTPUT);
  Serial.println("Sistema de Barreira Luminosa");
}

void loop()
{
  int  valorLuz = analogRead(LDR);
  Serial.print("Luminosidade: ");
  Serial.println(valorLuz);
  if(valorLuz < LIMITE_LUZ){
      Serial.println(" -> Presenca Detectada!");
    digitalWrite(LED_ALERTA, HIGH);
    tone(BUZZER, 1000);
  }else{
      Serial.println(" -> Sistema Normal!");
    digitalWrite(LED_ALERTA, LOW);
    tone(BUZZER, 500);
  }
}
