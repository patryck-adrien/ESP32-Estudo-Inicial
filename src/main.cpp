/* Projeto Curto Circuito – ESP32 comunicação Wi-Fi */

#include <WiFi.h>
#include <BluetoothSerial.h>

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

/*-------- Configurações de Wi-fi----------- */
// const char* ssid = "Machado Oi Fibra";  /* Substitua pelo nome da rede */
// const char* password =  "lucineia2019";    /* Substitua pela senha */
int led = 2;                       /* Se estiver utilizando um modelo ESP8266 utilize / / int led =D2 ; */

BluetoothSerial SerialBT;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  // /*---- Conecta ao Wi-Fi ---- */
  // WiFi.begin(ssid, password);
  // /*---- Enquanto estiver tentando conectar ---- */
  // while (WiFi.status() != WL_CONNECTED)
  // {
  //   delay(500);                                 /* Aguarda meio segundo */
  //   Serial.println("Conectando ao WiFi..");     /* Conectando */
  // }
  // Serial.println("Conectado"); /* Conectado */
  // Serial.print("Endereço de IP: ");
  // Serial.println(WiFi.localIP()); /* Exibe o endereço de IP */

}

void loop()
{
  // if (WiFi.status() == WL_CONNECTED)
  // { /* Se o ESP32 estiver conectado a internet */
  //   digitalWrite(led, 1);                /* Liga o LED */
  //   Serial.end();
  // }
  // else
  // { /* Se o ESP32 estiver desconectado */
  //   digitalWrite(led, 0);                /* Desliga LED */
  // }
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}