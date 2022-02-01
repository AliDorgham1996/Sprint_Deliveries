#ifndef MQTT_H_
#define MQTT_H_

#include <stdint.h>

typedef enum
{
	MQTT_EN_valid,
	MQTT_EN_Fail
}MQTT_Error_t;

MQTT_Error_t	 MQTT_Connect	(uint8_t* clientID);
MQTT_Error_t	 MQTT_Publish	(uint8_t* topic, uint8_t* message, uint32_t size, uint8_t QoS);
MQTT_Error_t	 MQTT_Subscribe	(uint8_t* topic);


#endif /* MQTT_H_ */