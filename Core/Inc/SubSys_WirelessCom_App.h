
#ifndef INC_SUBSYS_WIRELESSCOM_APP_H_
#define INC_SUBSYS_WIRELESSCOM_APP_H_
/******************************************************************************
         				#### WIRELESSCOM INCLUDES ####
******************************************************************************/
#include "SubSys_WirelessCom_Config.h"
#include "main.h"

/******************************************************************************
         				#### WIRELESSCOM DEFINITIONS ####
******************************************************************************/



/******************************************************************************
         				#### WIRELESSCOM ENUMS ####
******************************************************************************/
typedef enum{

	Sat_Carrier,
	Sat_Payload,
	GroundStation

}MissionUnit;


/******************************************************************************
         				#### WIRELESSCOM EXTERNS ####
******************************************************************************/

// WILL BE ADDED ALL TELEMETRY VARIABLES IN HERE



/******************************************************************************
         				#### WIRELESSCOM STRUCTS ####
******************************************************************************/

typedef struct{

	/***! Satellite Carrier Unit Variables ***/

		/*! Will be filled by MS5611 sensor*/
		float Carr_Pressure;		/* Unit : pascal 		(11Byte)e.g  => "101325.12"   	*/
		float Carr_VertSpeed;		/* Unit : meter/second	(6Byte) e.g  => "1, 10.2"etc.  	*/
		float Carr_VertHeight;		/* Unit : meter 		(4Byte) e.g  => "223.4"		  	*/
		float Carr_Temperature;		/* Unit : C°,celcius 	(5Byte) e.g  => "32.7"		  	*/

		/* Will be filled by used ADC interface*/
		float Carr_BatteryVoltage;	/* Unit : Voltage		(xByte) e.g => "8.2"			*/

		/* Will be filled by L-86 GPS*/
		float Carr_GPS_Latitude;	/* Unit : meter	  	    (xByte) e.g => "3150.7822" will be number, NMEA data it means 31° 50.7822 minute     */
		float Carr_GPS_Longitude;	/* Unit : degrees(°) 	(xByte) e.g => "11711.9278" will be number, NMEA data it means 117° 11.9278 minute	 */
		float Carr_GPS_Altitude;	/* Unit : degrees(°)	(xByte) e.g => "587"will be number , NMEA data it means 587meter from sea. GPGGA is provides */



	/***! Satellite Payload Unit Variables ***/

		/*! Will be filled by MS5611 senso r*/
		float PayLoad_Pressure;			/* Unit : pascal 		(11Byte) e.g => "101325.12"   	*/
		float PayLoad_VertSpeed;		/* Unit : meter/second	(6Byte) e.g  => "1, 10.2"etc.  	*/
		float PayLoad_VertHeight;		/* Unit : meter 		(4Byte) e.g  => "223.4"		  	*/
		float PayLoad_Temperature;		/* Unit : C°,celcius 	(5Byte) e.g  => "32.7"		  	*/

		/*! Will be filled by L-86 GPS sensor */
		float PayLoad_GPS_Latitude;		/* Unit : meter	  	    (xByte) e.g => "3150.7822" will be number, NMEA data it means 31° 50.7822 minute     */
		float PayLoad_GPS_Longitude;	/* Unit : degrees(°) 	(xByte) e.g => "11711.9278" will be number, NMEA data it means 117° 11.9278 minute	 */
		float PayLoad_GPS_Altitude;		/* Unit : degrees(°)	(xByte) e.g => "587" will be number , NMEA data it means 587meter from sea. GPGGA is provides */

		/*! Will be filled by BNO055 sensor */
		float PayLoad_Pitch;			/* Unit: degrees(°)		(xByte) e.g => "+180° to -180°" */
		float PayLoad_Roll;				/* Unit: degrees(°)		(xByte) e.g => "-90° to +90°"   */
		float PayLoad_Yaw;				/* Unit: degrees(°)		(xByte) e.g => "0° to +360°"   	*/

		/*! Will be filled by internal or external RTC unit or module */
		uint16_t Payload_Second, Payload_Minute, Payload_Hour, Payload_Day, Payload_Week, Payload_Year;

		/*! Will be filled by Payloads general algorithm */
		uint8_t SatelliteStat;			/* Unit : none 			(xByte) e.g => "0,to,5" */
		uint8_t ErrorCode;				/* Unit : none 			(xByte) e.g => "11001" */

		uint32_t TeamID;				/* Unit : none 			(xByte) e.g => "270061" */
		uint32_t PacketNum;				/* Unit : none 			(xByte) e.g => "123" */

		float VertHeight_Diff;			/* Unit : meter 		(xByte) e.g => "67.5" */
		float Station_IOTdata;			/* Unit : C°,celcius 	(xByte) e.g => "22.5" */

		char PayloadRHRH[4];			/* Unit : none 			(xByte) e.g => "4R6B" */

}SubSys_WirelessCom_VariableTypeDef;


typedef struct{

	char RxBuf[SizeOf_Wireless_RX_Buff]; /*! Buffer for Telemetry Datas that receive from wirelesscom*/
	char TxBuf[SizeOf_Wireless_TX_Buff]; /*! Buffer for Datas that send to Lora*/

}SubSys_WirelessCom_BufferTypeDef;

typedef struct{

	/*! Inner structs */
	SubSys_WirelessCom_BufferTypeDef WirelessBuf;
	SubSys_WirelessCom_VariableTypeDef	WirelessVar;

	/*! Used device DMA and Usart interface settings */
	UART_HandleTypeDef *huartX;
	DMA_HandleTypeDef *hdma_usartX_rx;
	DMA_HandleTypeDef *hdma_usartX_tx;

	/*! Target device Address and Channel settings */
	uint8_t Target_ADDH;
	uint8_t Target_ADDL;
	uint8_t Target_Ch;

	/*! Packet size of the message that will be sending and receiving */
	uint8_t SizeOf_Wireless_RX_Buff;
	uint8_t SizeOf_Wireless_TX_Buff;


}SubSys_WirelessCom_HandleTypeDef;



/******************************************************************************
         				#### WIRELESSCOM PROTOTYPES OF FUNCTIONS ####
******************************************************************************/
void SubSys_WirelessCom_Telemetry_Transfer_From_To(MissionUnit From_X, MissionUnit To_Y);
void SubSys_WirelessCom_Telemetry_Reception_From_To(MissionUnit From_X, MissionUnit To_Y);

//hangi cihazda bulunuyorsa neresi için görev yapacaksa ora için telemetri paketi oluşturacak
void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x);





#endif /* INC_SUBSYS_WIRELESSCOM_APP_H_ */
