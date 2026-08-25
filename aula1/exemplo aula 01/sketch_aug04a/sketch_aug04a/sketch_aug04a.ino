// C++ code
//

const byte AN = A0;

//vetor segmentos: a,b,c,d,e,f,g
const byte segmentos[7] = {2, 3, 4, 5, 6, 7, 8};

//numeros de 0 ate 5
const byte numeros[6][7]={
  {1,1,1,1,1,1,0}, //0
  {0,1,1,0,0,0,0}, //1
  {1,1,0,1,1,0,1}, //2
  {1,1,1,1,0,0,1}, //3
  {0,1,1,0,0,1,1}, //4
  {1,0,1,1,0,1,1}  //5
};

void setup()
{
      Serial.begin(9600);
     
      for (int i=0; i < 7; i++)
    {
          pinMode(segmentos[i], OUTPUT);
    }
}

void loop()
{
    // leitura analogica
      int leitura = analogRead(A0);
      Serial.println("AC: ");
      Serial.println(leitura);
      Serial.println(" | Tensao: ");
   
      //Converter 0-1024 para 0-5V
      float tensao = leitura *  5.0 / 1023.0;
      //Arredondar para exibicao no Display
      int numeroDisplay = tensao + 0.5;
     
      //restringir faixa de valores
      numeroDisplay = constrain(numeroDisplay, 0, 5);
         
      mostrarNumero(numeroDisplay);
     
      Serial.println("AC: ");
      Serial.println(leitura);
     
      Serial.println(" | Tensao: ");
      Serial.println(tensao, 2);
   
      Serial.println(" V | Display: ");
      Serial.println(numeroDisplay);
     
      delay(1000);
}
   
void mostrarNumero(int numero)
{
  for (int i=0; i<7; i++)
  {
    digitalWrite(
      segmentos[i],
      numeros[numero][i]
    );
  }
}
