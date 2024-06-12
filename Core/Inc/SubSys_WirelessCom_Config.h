/*
 * SubSys_WirelessCom_Config.h
 *
 *  Created on: Apr 28, 2024
 *      Author: yunus
 */

#ifndef INC_SUBSYS_WIRELESSCOM_CONFIG_H_
#define INC_SUBSYS_WIRELESSCOM_CONFIG_H_

/******************************************************************************
         				#### WIRELESSCOM INCLUDES ####
******************************************************************************/
#include "SubSys_WirelessCom_App.h"
#include "main.h"


/******************************************************************************
         				#### WIRELESSCOM ADDRESS DEFINATIONS ####
******************************************************************************/

#define REG_BaseAddress	 0x00

/******************************************************************************
         				#### WIRELESSCOM ENUMS ####
******************************************************************************/
typedef enum{

	UART_Rate_is_1200,
	UART_Rate_is_2400
	//keep going on

}dev_UART_Serial_Port_Rate;


typedef enum{

	p8N1,
	p8O1,
	//keep going on

}dev_Serial_Parity_Bit;


typedef enum{

	/*! "d" is dot as meaning */
	Air_Data_Rate_2d_4k,
	//keep going on
}dev_Air_Data_Rate;


typedef enum{
	bytes_200,
	bytes_128,
	//keep going on
}dev_SubPacket_Setting;


typedef enum{
	dBm30,
	dBm27,
	//keep going on
}dev_Transmitting_Power;


typedef enum{
	Transparent,
	Fixed_t
}dev_Transmission_Method;


typedef enum{
	DisableFea,
	EnableFea
}dev_SwithStatus;


typedef enum{
	ms500,
	ms1000,
	//keep going on
}dev_WOR_Cycle;

typedef enum{
	NormalMode, 		/*! UART and wireless channel areopen, transparent transmission is on */
	WORsending,			/*! WOR Transmitter (it sends packet in every period)*/
	WORreceiving,		/*! WOR Receiver (it sends packet in every period)*/
	DeepSleep			/*! Module goes to sleep (automatically wake up when configuring parameters*/
}dev_Mode_Switch;

typedef enum{
	writeCmnd = 0xC1,
	readCmnd  = 0xC2
}dev_Command;

/******************************************************************************
         				#### WIRELESSCOM INCLUDES STRUCTURES ####
******************************************************************************/

typedef struct Wirelesscom_Params_t{

	/*For REG0 Byte*/
	dev_UART_Serial_Port_Rate SerialPortRate;
	dev_Serial_Parity_Bit ParityBit;
	dev_Air_Data_Rate AirDataRate;

	/*For REG1 Byte*/
	dev_SubPacket_Setting SubPacket;
	dev_SwithStatus AmbientNoise_SW;
	dev_Transmitting_Power	TX_Power;

	/*For REG2 Byte*/
	uint8_t dev_Channel;

	/*For REG3 Byte*/
	dev_SwithStatus RSSIByte_SW;
	dev_Transmission_Method TransmissionMethod;
	dev_SwithStatus LBT_SW;
	dev_WOR_Cycle WorCycle;

}Wirelesscom_Params_t;


typedef struct dev_interfaces_t{

	/*! System Peripheral interfaces */
	UART_HandleTypeDef *huart;
	GPIO_TypeDef* GPIOx;

}dev_interfaces_t;

typedef struct WirelesscomConfig_HandleTypeDef{

	/*! Inner structs */
	Wirelesscom_Params_t param;
	dev_interfaces_t 	 interface;

	/**
	 * Lora M0 and M1 control pins and Normal, WOR, Sleep mode swtich
	 */
	uint16_t LORA_PIN_M0;
	uint16_t LORA_PIN_M1;
	dev_Mode_Switch Mode_SW;


/*!**		REGISTER VARIABLES		**!*/
	/*! For PARAMETER REG Bytes */
	uint8_t     REG0; /* UART Serial Port Rate || Parity Bit || Air Data Rate */
	uint8_t     REG1; /* SubPacket_Setting || RSSI_Ambient_Noise_Enable || Transmitting_Power  */
	uint8_t     REG2; /* Channel  */
	uint8_t     REG3; /* RSSI_Byte_Enable || Transmission_Method || LBT_Enable || WOR_Cycle */
	/*For CRYPTO REG HIGH & LOW Bytes */
	uint8_t   	REG_CRYPT_H;
	uint8_t   	REG_CRYPT_L;
	/*! For ADDRESS REG HIGH & LOW Bytes */
	uint8_t 	ADDH;
	uint8_t     ADDL;

}WirelesscomConfig_HandleTypeDef;


/******************************************************************************
         				#### WIRELESSCOM PROTOTYPES OF FUNCTIONS ####
******************************************************************************/

/**
  * @brief 	Configure parameters of ragisters, call sub function to write&read value to&from registers
  * @note  	User juct can create an object name like WirelessCom and send into this function by its address.
  * @param	*dev is an pointer that hold object address that create by user. All of configuration ops. is working by this pointer
  * @retval	currently empty
  */
void SubSys_WirelessCom_Config_Init(WirelesscomConfig_HandleTypeDef    *dev);


/**
  * @brief
  * @note
  * @param
  * @retval
  */
void SubSys_WirelessCom_Config_SET_REG(WirelesscomConfig_HandleTypeDef   *dev);


/**
  * @brief
  * @note
  * @param
  * @retval
  */
void SubSys_WirelessCom_Config_READ_REG(WirelesscomConfig_HandleTypeDef  *dev);


/**
  * @brief
  * @note
  * @param
  * @retval
  */
void SubSys_WirelessCom_Config_WORK_MODE(WirelesscomConfig_HandleTypeDef    *dev);



#endif /* INC_SUBSYS_WIRELESSCOM_CONFIG_H_ */
