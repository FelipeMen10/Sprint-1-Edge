#define TRIG_PIN 10 // Pino de disparo do sensor ultrassônico
#define ECHO_PIN 9  // Pino de eco do sensor ultrassônico
#define distancia_minima 10 // Distância em centímetros para detectar o objeto

#include <LiquidCrystal_I2C.h>  // Biblioteca para o LCD com interface I2C

// Criar objeto LCD com endereço I2C 0x27, 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2); 

unsigned long startTime = 0; // Variável para armazenar o tempo inicial
bool objeto_detectado = false; // Flag para indicar se um objeto foi detectado

void setup() {
  Serial.begin(9600); // Inicializar comunicação serial para depuração
  pinMode(TRIG_PIN, OUTPUT); // Configurar o pino TRIG como saída
  pinMode(ECHO_PIN, INPUT);  // Configurar o pino ECHO como entrada

  lcd.init(); // Inicializar o LCD
  lcd.backlight(); // Acender a luz de fundo do LCD
}

void loop() {
  // Enviar um pulso ultrassônico
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2); // Aguardar 2 microssegundos
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10); // Manter o pulso por 10 microssegundos
  digitalWrite(TRIG_PIN, LOW);

  // Ler o tempo do pulso de retorno
  long duracao = pulseIn(ECHO_PIN, HIGH);
  
  // Calcular a distância em centímetros
  long distancia = (duracao / 2) / 29.1;

  if (distancia < distancia_minima) { // Se a distância for menor que a mínima
    lcd.backlight(); // Acender a luz de fundo do LCD
    if (!objeto_detectado) { // Se o objeto não estava previamente detectado
      startTime = millis(); // Registrar o tempo inicial
      objeto_detectado = true; // Marcar o objeto como detectado
    }
    // Calcular e mostrar o tempo em tempo real
    unsigned long tempo_atual = millis(); // Obter o tempo atual
    unsigned long tempo_passado = tempo_atual - startTime; // Calcular o tempo decorrido
    unsigned long segundos = tempo_passado / 1000; // Converter milissegundos para segundos
    unsigned long milisegundos = tempo_passado % 1000; // Obter os milissegundos restantes
    lcd.setCursor(0, 0); // Definir o cursor na primeira linha
    lcd.print("Tempo passado: "); // Exibir a mensagem
    lcd.setCursor(0, 1); // Definir o cursor na segunda linha
    lcd.print(segundos); // Exibir os segundos
    lcd.print("."); // Exibir o ponto decimal
    if (milisegundos < 100) lcd.print("0"); // Adicionar zero para milissegundos menores que 100
    if (milisegundos < 10) lcd.print("0"); // Adicionar zero para milissegundos menores que 10
    lcd.print(milisegundos); // Exibir os milissegundos
    lcd.print(" segundos"); // Exibir a unidade de tempo
  } else { // Se a distância for maior ou igual à mínima
    if (objeto_detectado) { // Se o objeto estava previamente detectado
      objeto_detectado = false; // Marcar o objeto como não detectado
    }
    delay(2000); // Aguardar 2 segundos antes de limpar a tela
    lcd.clear(); // Limpar o display do LCD
    lcd.noBacklight(); // Apagar a luz de fundo do LCD
  }

  delay(10); // Pequeno atraso para evitar leituras muito rápidas
}
