#include "../MCAL/UART/UART.h"
#include "../Services/MQTT/MQTT_Cfg.h"
#include "../Library/Constants.h"
#include "MQTT.h"


_C _S uint8_t  protocolName[] = "MQTT";
_S uint16_t    packetIdent    = 1;


_S MQTT_Error_t sendUTFString(uint8_t* str)
{
	MQTT_Error_t return_value = MQTT_EN_valid;
	uint16_t len = strlen(str);
	return_value |= Uart_SendPooling(len>>8);
	return_value |= Uart_SendPooling(len);
	return_value |= Uart_SendStringPooling(str);		
	return return_value;
}

MQTT_Error_t MQTT_Connect(uint8_t* clientID)
{
	MQTT_Error_t return_value = MQTT_EN_valid;
	uint8_t remLen = (2 + strlen(protocolName)) + 1 + 1 + 2 + (2 + strlen(clientID));
	return_value |= Uart_SendPooling(MQTT_CONNECT_PACKET);
	return_value |= Uart_SendPooling(remLen);
	return_value |= sendUTFString(protocolName);
	return_value |= Uart_SendPooling(MQTT_PROTOCOL_LEVEL);
	return_value |= Uart_SendPooling(MQTT_CONNECT_FLAGS);
	return_value |= Uart_SendPooling(MQTT_KEEP_ALIVE_TIME);
	return_value |= Uart_SendPooling(MQTT_KEEP_ALIVE_TIME);
	return_value |= sendUTFString(clientID);
	return return_value;
}
MQTT_Error_t MQTT_Publish(uint8_t* topic, uint8_t* message, uint32_t size, uint8_t QoS)
{
	MQTT_Error_t return_value = MQTT_EN_valid;
	uint8_t remLen = (2 + strlen(topic)) + size;
	uint32_t ind = 0;
	if(QoS > 0)
	{
		return_value |= Uart_SendPooling(MQTT_PUBLISH_PACKET_QOS_1);
		remLen += 2;
	}
	else
	{
		return_value |= Uart_SendPooling(MQTT_PUBLISH_PACKET_QOS_0);
	}
	return_value |= Uart_SendPooling(remLen);
	return_value |= sendUTFString(topic);
	if(QoS > 0)
	{
		return_value |= Uart_SendPooling(packetIdent>>8);
		return_value |= Uart_SendPooling((uint8_t)packetIdent);
		packetIdent++;
	}
	for (ind = 0; ind < size; ind++)
	{
		return_value |= Uart_SendPooling(message[ind]);
	}
	return return_value;
}
MQTT_Error_t MQTT_Subscribe(uint8_t* topic)
{
	MQTT_Error_t return_value = MQTT_EN_valid;
	uint8_t remLen = 2 + (2 + strlen(topic)) + 1;
	return_value |= Uart_SendPooling(MQTT_SUBSCRIBE_PACKET);
	return_value |= Uart_SendPooling(remLen);

	return_value |= Uart_SendPooling(packetIdent>>8);
	return_value |= Uart_SendPooling((uint8_t)packetIdent);
	packetIdent++;
	
	return_value |= sendUTFString(topic);
	return_value |= Uart_SendPooling(MQTT_SUBSCRIBE_QOS);
	
	return return_value;
}