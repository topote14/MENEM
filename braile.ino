#define pin_int 2

bool teclado[8] = {0, 0, 0, 0, 0, 0, 0, 0};
bool envio = false;

void setup() {
  // put your setup code here, to run once:
  int i;
  attachInterrupt(0, leer, RISING);
  attachInterrupt(1, mostrar, FALLING);
  pinMode(pin_int, INPUT);  //pin utilizado para las interrupciones
  for (i = 3; i < 11; i ++) {
    pinMode(i, INPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:
  
}

void leer() {
  //int i;
  while (true) {
    for (int i = 0; i < 8; i++) {
      teclado[i] = digitalRead(i + 4);
    }
  }
}

void mostrar() {
  int i;
  for (i = 0; i < 8; i++) {
    Serial.print(teclado[i]);
  }
  Serial.println();
  loop();
}

