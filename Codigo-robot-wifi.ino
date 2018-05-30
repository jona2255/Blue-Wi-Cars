
//Incluir librerias

#include <ESP8266WiFi.h>

//Definir puerto
  WiFiClient client;
  WiFiServer server(80);

//Configuración Wi-Fi
  const char* ssid = "SuperXEiLL";
  const char* password = "";

  #include <ESP8266WiFi.h>

//Datos recibidos de la aplicación
  String  data ="";


//Pines Motor Driver

//Pines de control

  int Pin_Motor_Der_A = D8; // Antiguo D8 - 15
  int Pin_Motor_Der_B = D7; // Antiguo D7 - 13
  int Pin_Motor_Izq_A = D4; // Antiguo D4 - 2
  int Pin_Motor_Izq_B = D3;  // Antiguo D3 - 0

//Pines habilitar motor

  int Motor_Der_Hab = D6;  // Antiguo D6 - 12
  int Motor_Izq_Hab = D5;  // Antiguo D5 - 14

  int tiempo=0;

  void setup()
  {

 Serial.begin(115200);
  connectWiFi();
//  server.begin();

// configuramos los pines como salida
  pinMode(Pin_Motor_Der_A, OUTPUT);
  pinMode(Pin_Motor_Der_B, OUTPUT);
  pinMode(Pin_Motor_Izq_A, OUTPUT);
  pinMode(Pin_Motor_Izq_B, OUTPUT);
  pinMode(Motor_Der_Hab, OUTPUT);
  pinMode(Motor_Izq_Hab, OUTPUT);

//Comenzar la comunicación con el servidor
  server.begin();
}

  void loop() {
  // put your main code here, to run repeatedly:

   // Si el servidor está disponible, usa la función "checkClient"

    client = server.available();
    if (!client) return;
    data = checkClient ();

        Serial.println(data);



     if(data =="f")Mover_Adelante();

     else if(data =="b")Mover_Retroceso();

     else if(data =="r")Girar_Derecha();

     else if(data =="l")Girar_Izquierda();

     else if(data == "s")Mover_Stop();

      }



void Mover_Adelante(void)
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}

void Mover_Retroceso(void)
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A,LOW );
  digitalWrite (Pin_Motor_Der_B,HIGH );
  digitalWrite (Pin_Motor_Izq_A,LOW );
  digitalWrite (Pin_Motor_Izq_B,HIGH );
}


void Girar_Derecha(void)
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, HIGH);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}

void Girar_Izquierda(void)
{
  digitalWrite (Motor_Der_Hab, HIGH);
  digitalWrite (Motor_Izq_Hab, HIGH);
  digitalWrite (Pin_Motor_Der_A, HIGH);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}

void Mover_Stop(void)
{
  digitalWrite (Motor_Der_Hab, LOW);
  digitalWrite (Motor_Izq_Hab, LOW);
  digitalWrite (Pin_Motor_Der_A, LOW);
  digitalWrite (Pin_Motor_Der_B, LOW);
  digitalWrite (Pin_Motor_Izq_A, LOW);
  digitalWrite (Pin_Motor_Izq_B, LOW);
}


//Recibit datos de la aplicación

  String checkClient (void)
  {
    while(!client.available()) delay(1);
    String request = client.readStringUntil('\r');
    request.remove(0, 5);
    request.remove(request.length()-9,9);
    return request;
  }

  void connectWiFi()
  {
    Serial.println("Connecting to WIFI");
    WiFi.begin(ssid, password);
    while ((!(WiFi.status() == WL_CONNECTED)))
    {
      delay(300);
      Serial.print("..");
    }
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("NodeMCU Local IP is : ");
    Serial.print((WiFi.localIP()));
  }
