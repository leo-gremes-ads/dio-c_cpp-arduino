#include <DHT.h>  // Biblioteca para o sensor DHT11 ou DHT22

#define DHTPIN 2         // Pino onde o sensor DHT está conectado
#define DHTTYPE DHT11    // Tipo do sensor (DHT11 ou DHT22)
#define FAN_PIN 3        // Pino onde o relé do ventilador está conectado

DHT dht(DHTPIN, DHTTYPE); // Inicializa o sensor DHT

void setup()
{
	Serial.begin(9600);  // Inicializa a comunicação serial
	dht.begin();         // Inicializa o sensor DHT
	pinMode(FAN_PIN, OUTPUT); // Define o pino do ventilador como saída
}

void loop()
{
	// Lê a temperatura do sensor
	float temp = dht.readTemperature();

	// Verifica se a leitura foi bem-sucedida
	if (isnan(temp)) {
		Serial.println("Falha na leitura do sensor!");
		return;
	}
	Serial.print("Temperatura: ");
	Serial.print(temp);
	Serial.println("°C");
	// Se a temperatura for maior que 27°C, liga o ventilador
	if (temp > 27.0) {
		digitalWrite(FAN_PIN, HIGH);
		Serial.println("Ventilador ligado!");
	} else {
		digitalWrite(FAN_PIN, LOW);
		Serial.println("Ventilador desligado!");
	}
	// Tempo para realizar uma nova leitura, em ms
	delay(2000);
}
