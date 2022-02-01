#ifndef MQTT_CFG_H_
#define MQTT_CFG_H_

#define MQTT_CONNECT_PACKET			0x10
#define MQTT_PROTOCOL_LEVEL			0x04
#define MQTT_CONNECT_FLAGS			0x02
#define MQTT_KEEP_ALIVE_TIME		0xFF
#define MQTT_PUBLISH_PACKET_QOS_0	0x30
#define MQTT_PUBLISH_PACKET_QOS_1   0x32
#define MQTT_SUBSCRIBE_PACKET		0x82

#define MQTT_QOS_0					0x00
#define MQTT_QOS_1					0x01
#define MQTT_SUBSCRIBE_QOS			MQTT_QOS_1


#endif /* MQTT_CFG_H_ */