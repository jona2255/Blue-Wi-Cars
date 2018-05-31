
//Pines de conexión del driver
int Pin_Motor_Der_A = 10;
int Pin_Motor_Der_B = 11;
int Pin_Motor_Izq_A = 12;
int Pin_Motor_Izq_B = 13;

int Motor_Der_Hab = 6;
int Motor_Izq_Hab = 5;

int tiempo=0;
void setup() {
  // inicializar la comunicación serial a 9600 bits por segundo:
  Serial.begin(9600);
  // configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  pinMode(Motor_Der_Hab, OUTPUT);
  pinMode(Motor_Izq_Hab, OUTPUT);
}

void loop() {

  if (Serial.available()) {
     char dato= Serial.read();
     if(dato=='f')
     {
        Mover_Adelante();
        tiempo=0;
     }
     else if(dato=='b')
     {
        Mover_Retroceso();
        tiempo=0;
     }
     else if(dato=='r')
     {
        Mover_Derecha();
        tiempo=0;
     }
     else if(dato=='l')
     {
        Mover_Izquierda();
        tiempo=0;
     }
     else if(dato=='s')
     {
        Mover_Stop();
        tiempo=0;
     }

  }

}

void Mover_Adelante()
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
void Mover_Retroceso()
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}
void Mover_Derecha()
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A,HIGH);
  digitalWrite (Pin_Motor_Der_B,LOW);
  digitalWrite (Pin_Motor_Izq_A,LOW);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Izquierda()
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A,LOW);
  digitalWrite (Pin_Motor_Der_B,LOW);
  digitalWrite (Pin_Motor_Izq_A,HIGH);
  digitalWrite (Pin_Motor_Izq_B,LOW);
}
void Mover_Stop()
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}
