// ==========================================================
// Projeto 6: Controle de Cores do LED RGB com Botão
// Versão limpa de caracteres invisíveis
// ==========================================================

// Mapeamento dos pinos do Arduino conforme a imagem
const int pinoBotao = 2; // Pino do botão atualizado conforme a imagem
const int pinoRed = 7;   // Canal Vermelho
const int pinoGreen = 6; // Canal Verde
const int pinoBlue = 5;  // Canal Azul

// Variáveis de controle de estado do sistema
int estadoCor = 0;              // 0 = Apagado, 1 = Vermelho, 2 = Verde, 3 = Azul
int estadoBotaoAnterior = LOW; // Botão inicia em LOW

// Protótipos das funções
void acendeVermelho();
void acendeVerde();
void acendeAzul();
void apagaLed();

void setup() {
  // Configura o pino do botão como entrada
  pinMode(pinoBotao, INPUT);
  
  // Configura os pinos do LED RGB como saídas digitais
  pinMode(pinoRed, OUTPUT);
  pinMode(pinoGreen, OUTPUT);
  pinMode(pinoBlue, OUTPUT);
  
  // O LED inicia totalmente apagado
  apagaLed();
}

void loop() {
  // Leitura do estado atual do botão
  int leituraBotao = digitalRead(pinoBotao);

  // Detecção da borda de subida (solto [LOW] -> pressionado [HIGH])
  if (leituraBotao == HIGH && estadoBotaoAnterior == LOW) {
    estadoCor++; // Incrementa o estado do sinalizador

    // Reseta o ciclo se ultrapassar o 3º estado
    if (estadoCor > 3) {
      estadoCor = 0;
    }

    // Seleciona a cor correspondente ao estado atual
    switch (estadoCor) {
      case 0:
        apagaLed();
        break;
      case 1:
        acendeVermelho();
        break;
      case 2:
        acendeVerde();
        break;
      case 3:
        acendeAzul();
        break;
    }

    // Filtro de debounce
    delay(200);
  }

  // Atualiza a memória da leitura do botão
  estadoBotaoAnterior = leituraBotao;
}

// ==========================================================
// Funções de Controle do LED RGB (Cátodo Comum)
// ==========================================================

void acendeVermelho() {
  digitalWrite(pinoRed, HIGH);   // Liga Vermelho
  digitalWrite(pinoGreen, LOW);  // Desliga Verde
  digitalWrite(pinoBlue, LOW);   // Desliga Azul
}

void acendeVerde() {
  digitalWrite(pinoRed, LOW);    // Desliga Vermelho
  digitalWrite(pinoGreen, HIGH); // Liga Verde
  digitalWrite(pinoBlue, LOW);   // Desliga Azul
}

void acendeAzul() {
  digitalWrite(pinoRed, LOW);    // Desliga Vermelho
  digitalWrite(pinoGreen, LOW);  // Desliga Verde
  digitalWrite(pinoBlue, HIGH);  // Liga Azul
}

void apagaLed() {
  digitalWrite(pinoRed, LOW);    // Desliga Vermelho
  digitalWrite(pinoGreen, LOW);  // Desliga Verde
  digitalWrite(pinoBlue, LOW);   // Desliga Azul
}
