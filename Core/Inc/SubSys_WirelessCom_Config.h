

/** !WARNING
 * Satellite Carrier Unit's adress will be 0x1923  and channel is 0x11
 * Satellite Payload Unit's adress will be 0x1453  and channel is 0x22
 * Satellite Ground Station adress will be 0x1071  and channel is 0x33
 */
#ifndef SAT_PERIPHERALS_LIB_INC_SUBSYS_WIRELESSCOM_CONFIG_H_
#define SAT_PERIPHERALS_LIB_INC_SUBSYS_WIRELESSCOM_CONFIG_H_

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
	UART_Rate_is_2400,
	UART_Rate_is_4800,
	UART_Rate_is_9600,
	UART_Rate_is_19200,
	UART_Rate_is_38400,
	UART_Rate_is_57600,
	UART_Rate_is_115200

}dev_UART_Serial_Port_Rate;


typedef enum{

	p8N1,
	p8O1,
	p8E1,

}dev_Serial_Parity_Bit;


typedef enum{

	/*! "d" is a dot, "k" is kilo(1000) */
	Air_Data_Rate_2d_4k = 0,
	Air_Data_Rate_4d_8k = 3,
	Air_Data_Rate_9d_6k,
	Air_Data_Rate_19d_2k,
	Air_Data_Rate_38d_4k,
	Air_Data_Rate_62d_5k

}dev_Air_Data_Rate;


typedef enum{

	bytes_200,
	bytes_128,
	bytes_64,
	bytes_32

}dev_SubPacket_Setting;


typedef enum{

	dBm30,
	dBm27,
	dbm24,
	dbm21

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
	/*! ms is milisecond */
	ms500,
	ms1000,
	ms1500,
	ms2000,
	ms2500,
	ms3000,
	ms3500,
	ms4000

}dev_WOR_Cycle;

typedef enum{

	NormalMode, 		/*! UART and wireless channel areopen, transparent transmission is on */
	WORsending,			/*! WOR Transmitter (it sends packet in every period)*/
	WORreceiving,		/*! WOR Receiver (it sends packet in every period)*/
	DeepSleep			/*! Module goes to sleep (automatically wake up when configuring parameters*/

}dev_Mode_Switch;

typedef enum{

	writeCmnd = 0xC0,
	readCmnd  = 0xC1

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
	uint8_t     REG0; 				/* UART Serial Port Rate || Parity Bit || Air Data Rate */
	uint8_t     REG1;			 	/* SubPacket_Setting || RSSI_Ambient_Noise_Enable || Transmitting_Power  */
	uint8_t     REG2; 				/* Channel  */
	uint8_t     REG3; 				/* RSSI_Byte_Enable || Transmission_Method || LBT_Enable || WOR_Cycle */

	/*For CRYPTO REG HIGH & LOW Bytes */
	uint8_t   	REG_CRYPT_H;
	uint8_t   	REG_CRYPT_L;

	/*! For ADDRESS REG HIGH & LOW Bytes */
	uint8_t 	ADDH;
	uint8_t     ADDL;

}SubSys_WirelesscomConfig_HandleTypeDef;


/******************************************************************************
         			#### WIRELESSCOM PROTOTYPES OF FUNCTIONS ####
******************************************************************************/

/**
  * @brief 	Configure parameters of ragisters, call sub function to write&read value to&from registers
  * @note
  * @param	*dev, is a pointer that hold object address that create by user. All of configuration ops. is working by this pointer
  * @retval	currently empty
  */
void SubSys_WirelessCom_Config_Init(SubSys_WirelesscomConfig_HandleTypeDef    *dev);


/**
  * @brief Sets the selected parameter and sends it to the wireless communication device
  * @note
  * @param *dev, is a pointer that hold object address that create by user. All of configuration ops. is working by this pointer
  * @retval NONE
  */
void SubSys_WirelessCom_Config_SET_REG(SubSys_WirelesscomConfig_HandleTypeDef   *dev);


/**
  * @brief Read configuration register's value and checks with the correct value,
  * 	    If there is an error stop the algorithm and lock it
  * @note	An error logger will be added soon
  * @param *dev, is a pointer that hold object address that create by user. All of configuration ops. is working by this pointer
  * @retval NONE
  */
void SubSys_WirelessCom_Config_READ_REG(SubSys_WirelesscomConfig_HandleTypeDef  *dev);


/**
  * @brief Selects work mode like transparent transmission, wor communication and deep sleep
  * @note
  * @param *dev, is a pointer that hold object address that create by user. All of configuration ops. is working by this pointer
  * @retval NONE
  */
void SubSys_WirelessCom_Config_WORK_MODE(SubSys_WirelesscomConfig_HandleTypeDef   *dev);


#endif /* SAT_PERIPHERALS_LIB_INC_SUBSYS_WIRELESSCOM_CONFIG_H_ */
