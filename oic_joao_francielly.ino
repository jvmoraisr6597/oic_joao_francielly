#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "VIVO-0389";
const char* password = "2F8A550389";
const char* mqtt_server = "broker.mqtt-dashboard.com";


WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
String LampadaQuarto = "";
String SensorSonoro = "";
bool som;
bool aceso;
void setup_wifi() {
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String topicRecieved = topic;
  for (int i = 0; i < length; i++) {
    if (topicRecieved == "oic2021/light28") {
      LampadaQuarto="";
      LampadaQuarto+=(char)payload[i];
      Serial.println(topic);
    } else {
      SensorSonoro = "";
      SensorSonoro = (char)payload[i];
      Serial.println(topic);
    }
    
  }
  Serial.println(SensorSonoro);
  Serial.println(LampadaQuarto);
 

}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      client.subscribe("oic2021/light28");
      client.subscribe("oic2021/sensor28");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pinMode(D1, OUTPUT);
  pinMode(D0, INPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  som = digitalRead(D0);
  long now = millis();
  if (now - lastMsg > 2000) {
    if (LampadaQuarto.toInt() == 1) {
      digitalWrite(D1, HIGH);
      aceso = 1;
    } else {
      digitalWrite(D1, LOW);
      aceso = 0;
    }
    if(som == 0 and SensorSonoro.toInt() == 1) {
        if(aceso == 0) {
          digitalWrite(D1, HIGH);
          aceso = 1;
          client.publish("oic2021/light28", "1");
        } else {
          digitalWrite(D1, LOW);
          aceso = 0;
          client.publish("oic2021/light28", "0");
        }
    }

  }
}
