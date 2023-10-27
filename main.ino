#include <IRremote.h> //INCLUSÃO DE BIBLIOTECA

int RECV_PIN = 7; //PINO DIGITAL UTILIZADO PELO FOTORRECEPTOR KY-022
IRrecv irrecv(RECV_PIN); //PASSA O PARÂMETRO PARA A FUNÇÃO irrecv
decode_results results; //VARIÁVEL QUE ARMAZENA OS RESULTADOS (SINAL IR RECEBIDO)

#define ledr 2
#define bt 3
#define door 5
int btstate = 0;
int codTecla1 = 4294967295;

void opendoor() {
  Serial.println("OPEN");
  digitalWrite(door,HIGH);
  delay(500);
  digitalWrite(door,LOW);
}

void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  irrecv.enableIRIn(); //INICIALIZA A RECEPÇÃO DE SINAIS IR

  pinMode(ledr,OUTPUT);
  pinMode(bt,INPUT);
  pinMode(door,OUTPUT);
}

void loop(){
  //CAPTURA O SINAL IR
  if (irrecv.decode(&results)) {
    if((results.value) == codTecla1){
      opendoor();
    }
  }
  irrecv.resume();
  delay(100); //INTERVALO DE 100 MILISSEGUNDOS
}
