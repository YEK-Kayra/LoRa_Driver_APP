
/**
 * Gelen değişken isimleri ile gönderim yapılacak değişken isimleri aynı olmamalı
 * Sd karta veri kaydı yapacağın zaman da kayıt değişkenleri SD ile başlasın
 * !!!!!SEVDA KUŞU KANADINDAA yazılacak ilk mesaj!!!!
 *
 * sonraki kalan updatelerde pos mask ile makrolama işlemlerine çevireceğiz enum yerine
 * #define DMA_HISR_TCIF7_Pos       (27U)
 * #define DMA_HISR_TCIF7_Msk       (0x1UL << DMA_HISR_TCIF7_Pos)                   0x0800000
 * #define DMA_HISR_TCIF7           DMA_HISR_TCIF7_Msk  ==> sadece ilgili biti aktif edilmiş register
 */


/**
 * PLAN ŞU
 * değişkenleri sprintf ile bir karakter dizisine byte byte kaydetmen , o yüzden byte sayısını karakter sayısına göre ayarla
 */
#ifndef SAT_PERIPHERALS_LIB_INC_SUBSYS_WIRELESSCOM_APP_H_
#define SAT_PERIPHERALS_LIB_INC_SUBSYS_WIRELESSCOM_APP_H_
/******************************************************************************
         				#### WIRELESSCOM INCLUDES ####
******************************************************************************/
#include "SubSys_WirelessCom_Config.h"
#include "main.h"

/******************************************************************************
         				#### WIRELESSCOM DEFINITIONS ####
******************************************************************************/

/*! Packet size of the message that will be sending and receiving */
#define SizeOf_Wireless_RX_Buff 	10		//Will be update
#define SizeOf_Wireless_TX_Buff 	10		//Will be update


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


/******************************************************************************
         				#### WIRELESSCOM STRUCTS ####
******************************************************************************/

typedef struct{

	/***! Satellite Carrier Unit Variables ***/

		/*! Will be filled by MS5611 sensor*/
		float Carr_Pressure;		/* Unit : pascal 		(12Byte)e.g  => "101325.5938"   			*/
		float Carr_VertSpeed;		/* Unit : meter/second	(5Byte) e.g  => "1.0, 10.2, 158.7 "		  	*/
		float Carr_VertHeight;		/* Unit : meter 		(6Byte) e.g  => "223.4, 1023.7"		  		*/
		float Carr_Temperature;		/* Unit : C°,celcius 	(4Byte) e.g  => "32.7"		  				*/

		/* Will be filled by used ADC interface*/
		float Carr_BatteryVoltage;	/* Unit : Voltage		(4Byte) e.g => "8.25"						*/

		/* Will be filled by L-86 GPS*/
		float Carr_GPS_Latitude;	/* Unit : degrees and minute(°)(')	(11Byte) e.g => "3150.7822N"  ,	NMEA data it means 31° 50.7822' minute 	'N' will be send separately		 */
		float Carr_GPS_Longitude;	/* Unit : degrees and minute(°)(') 	(11Byte) e.g => "11711.9278E" , NMEA data it means 117° 11.9278 minute	'E' will be send separately		 */
		float Carr_GPS_Altitude;	/* Unit : meter 					(6Byte) e.g =>  "1214.4"	  , NMEA data it means 1214.4 meter from sea. GPGGA is provides 			 */
		char Carr_GPS_CompassWay_Longtitude; 	/* Unit : char 		(1Byte) e.g => "N or S"   */
		char Carr_GPS_CompassWay_Latitude; 		/* Unit : char 		(1Byte) e.g => "E or W"   */



	/***! Satellite Payload Unit Variables ***/

		/*! Will be filled by MS5611 senso r*/
		float PayLoad_Pressure;			/* Unit : pascal 		(12Byte)e.g  => "101325.5938"   			*/
		float PayLoad_VertSpeed;		/* Unit : meter/second	(5Byte) e.g  => "1.0, 10.2, 158.7 "		  	*/
		float PayLoad_VertHeight;		/* Unit : meter 		(6Byte) e.g  => "223.4, 1023.7"		  		*/
		float PayLoad_Temperature;		/* Unit : C°,celcius 	(4Byte) e.g  => "32.7"		  				*/

		/*! Will be filled by L-86 GPS sensor */
		float PayLoad_GPS_Latitude;		/* Unit : degrees and minute(°)(')	(11Byte) e.g => "3150.7822N"  ,	NMEA data it means 31° 50.7822' minute 	'N' will be send separately		*/
		float PayLoad_GPS_Longitude;	/* Unit : degrees and minute(°)(') 	(11Byte) e.g => "11711.9278E" , NMEA data it means 117° 11.9278 minute	'E' will be send separatel		*/
		float PayLoad_GPS_Altitude;		/* Unit : meter 					(6Byte)  e.g =>  "1214.4"	  , NMEA data it means 1214.4 meter from sea. GPGGA is provides 			*/
		char  Payload_GPS_CompassWay_Longtitude; 	/* Unit : char 		(1Byte) e.g => "N or S"   */
		char  Payload_GPS_CompassWay_Latitude; 		/* Unit : char 		(1Byte) e.g => "E or W"   */

		/*! Will be filled by BNO055 sensor */
		float PayLoad_Pitch;			/* Unit: degrees(°)		(7Byte) e.g => "±112.54" 	*/
		float PayLoad_Roll;				/* Unit: degrees(°)		(7Byte) e.g => "±112.54"   	*/
		float PayLoad_Yaw;				/* Unit: degrees(°)		(7Byte) e.g => "±112.54"   	*/

		/* Will be filled by used ADC interface*/
		float Payload_BatteryVoltage;	/* Unit : Voltage		(4Byte) e.g => "8.25"	*/


		/*! Will be filled by internal or external RTC unit or module */
		uint16_t Payload_Second, Payload_Minute, Payload_Hour, Payload_Day, Payload_Month, Payload_Year; /* Unit : (Day/Month/Year**Hour/Minute/Second) (20Byte) e.g => 12/06/2024**17/54/23 */

		/*! Will be filled by Payloads general algorithm */

		/**!! "SatelliteStat" variable
		 *
		 * Numbers => |  	 	0		 |        1	     |  		   2		    |    	  3		    |   	   4		|                 5  				  |
		 * Station => |  ReadyForFlight	 |     Ascent	 |  Model Satellite Descent	|     Separation	|  Payload Descent	|  Recovery (Payload Ground Contact)  |
		 */
		uint8_t SatelliteStat;			/* Unit : none 			(1Byte) e.g => "0,to,5" */


		/**!! "ErrorCode" variable
		 *
		 * index information => |Satt. velocity is not range 12-14ms | (index 0)
		 * 						|Payload. velocity is not range 6-8ms| (index 1)
		 * 						|Unable to get carrier pressure		 | (index 2)
		 * 						|Unable to get payload location		 | (index 3)
		 * 						|Autonomous separation did not occur | (index 4)
		 */
		uint8_t ErrorCode;				/* Unit : none 			(5Byte) e.g => "11001" */


		/**!! "PayloadRHRH" variable
		 *	N is a number between 0-9 , L is a letter ( R(red) G(green) B(blue) N(nofilter) )
		 */
		char Payload_Filter_NLNL[4];			/* Unit : none 			(4Byte) e.g => "4R6B" */

		/* Will be filled definations*/
		uint32_t TeamID;				/* Unit : none 			(6Byte) e.g => "270061" */
		uint32_t PacketNum;				/* Unit : none 			(5Byte) e.g => "65535" 	*/

		/* Will be synthesized with altitude datas*/
		float VertHeight_Diff;			/* Unit : meter 		(5Byte) e.g => "677.5" 	*/

		/* Will be picked up from the ground station*/
		float Station_IOTdata;			/* Unit : C°,celcius 	(4Byte) e.g => "22.5" 	*/

		uint8_t Satellite_ManuelSep;

}SubSys_WirelessCom_VariableTypeDef;

typedef struct{

	char Rx[SizeOf_Wireless_RX_Buff]; /*! Buffer for Telemetry Datas that receive from wirelesscom*/
	char Tx[SizeOf_Wireless_TX_Buff]; /*! Buffer for Datas that send to Lora*/

}SubSys_WirelessCom_BufferTypeDef;

typedef struct{

	/*! Inner structs */
	SubSys_WirelessCom_BufferTypeDef Buffer;
	SubSys_WirelessCom_VariableTypeDef	Variable;

	/*! Used device DMA and Usart interface settings */
	UART_HandleTypeDef *huartX;
	DMA_HandleTypeDef *hdma_usartX_rx;
	DMA_HandleTypeDef *hdma_usartX_tx;

	/*! Target device Address and Channel settings */
	uint8_t Target_ADDH;
	uint8_t Target_ADDL;
	uint8_t Target_Ch;

}SubSys_WirelessCom_APP_HandleTypeDef;




/******************************************************************************
         				#### WIRELESSCOM PROTOTYPES OF FUNCTIONS ####
******************************************************************************/

void SubSys_WirelessCom_Telemetry_Init(SubSys_WirelessCom_APP_HandleTypeDef *APPdev);

void SubSys_WirelessCom_Telemetry_Transfer_From_To(MissionUnit From_X, MissionUnit To_Y);
void SubSys_WirelessCom_Telemetry_Reception_From_To(MissionUnit From_X, MissionUnit To_Y);

//hangi cihazda bulunuyorsa neresi için görev yapacaksa ora için telemetri paketi oluşturacak
void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x);





#endif /* INC_SUBSYS_WIRELESSCOM_APP_H_ */
