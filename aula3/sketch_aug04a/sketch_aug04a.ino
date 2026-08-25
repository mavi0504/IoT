// Entrada analógica do potenciômetro
const byte POTENCIOMETRO = A5;

// Saída PWM para controlar o brilho do LED
const byte LED = 11;

// Pinos dos segmentos do display
const byte segmentoA = 2;
const byte segmentoB = 3;
const byte segmentoC = 4;
const byte segmentoD = 5;
const byte segmentoE = 6;
const byte segmentoF = 7;
const byte segmentoG = 8;

// Matriz dos números de 0 a 9
// Ordem dos segmentos: A, B, C, D, E, F, G
const byte numeros[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  pinMode(LED, OUTPUT);

  pinMode(segmentoA, OUTPUT);
  pinMode(segmentoB, OUTPUT);
  pinMode(segmentoC, OUTPUT);
  pinMode(segmentoD, OUTPUT);
  pinMode(segmentoE, OUTPUT);
  pinMode(segmentoF, OUTPUT);
  pinMode(segmentoG, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // Leitura analógica: de 0 até 1023
  int valorAnalogico = analogRead(POTENCIOMETRO);

  // Converte 0–1023 para 0–255
  int valorPWM = map(valorAnalogico, 0, 1023, 0, 255);

  // Controla a intensidade do LED
  analogWrite(LED, valorPWM);

  // Calcula a tensão aproximada entre 0 e 5 V
  float tensao = valorAnalogico * (5.0 / 1023.0);

  // Arredonda a tensão para mostrar de 0 a 5 no display
  int tensaoInteira = round(tensao);

  // Exibe o valor no display
  mostrarNumero(tensaoInteira);

  // Mostra informações no Monitor Serial
  Serial.print("Leitura analogica: ");
  Serial.print(valorAnalogico);

  Serial.print(" | PWM: ");
  Serial.print(valorPWM);

  Serial.print(" | Tensao: ");
  Serial.print(tensao, 2);
  Serial.println(" V");

  delay(200);
}

void mostrarNumero(byte numero) {
  if (numero > 9) {
    return;
  }

  digitalWrite(segmentoA, numeros[numero][0]);
  digitalWrite(segmentoB, numeros[numero][1]);
  digitalWrite(segmentoC, numeros[numero][2]);
  digitalWrite(segmentoD, numeros[numero][3]);
  digitalWrite(segmentoE, numeros[numero][4]);
  digitalWrite(segmentoF, numeros[numero][5]);
  digitalWrite(segmentoG, numeros[numero][6]);
}
