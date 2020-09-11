#include "mqttHandler.h"


WiFiClient espClient;
PubSubClient client(espClient);


void MqttHandler::setupMqtt() {
    client.setServer(MQTT_BROKER, MQTT_PORT);
    connectToBroker();
}

void MqttHandler::connectToBroker() {
    client.connect(HOSTNAME, MQTT_USER, MQTT_PASSWORD);
}

void MqttHandler::sendValues(int volume, int level) {
    if(client.connected()) {
        char tempString[DIGITS_VOLUME];
        itoa(level, tempString, 10);
        client.publish(TOPIC_LEVEL, tempString, true);
        itoa(volume, tempString, 10);
        client.publish(TOPIC_VOLUME, tempString, true);
    }
}

void MqttHandler::loopClient() {
    if(!client.loop()) {
        connectToBroker();
    }
}
