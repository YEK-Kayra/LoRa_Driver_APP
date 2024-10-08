/******************************************************************************
         				#### WIRELESSCOM INCLUDES ####
******************************************************************************/
#include "SubSys_WirelessCom_App.h"

/******************************************************************************
         				#### WIRELESSCOM VARIABLES ####
******************************************************************************/
uint16_t Written_Bytes; /* is for save number of total converted buffer's characters*/


/******************************************************************************
         				#### WIRELESSCOM  FUNCTIONS ####
******************************************************************************/
/**
  * @brief Decimal, float and other formats are converted as character and save them into the TX buffer.
  * 		When TX buffer is fulfilled , it is sent by UART interface.
  * @note  Follow the transmitting rules, each if and else if has a why head for using
  * @param MissionUnit From_X, Packet type used for your specific purpose. Where do you  want to take it, select that.
  * 																	  @arg 0 : Sat_Carrier
  * 																 	  @arg 1 : Sat_Payload
  * 																  	  @arg 2 : Ground_Sation
  * @param MissionUnit To_Y, Packet type used for your specific purpose. Where do you want to send it, select that.
  * 																	  @arg 0 : Sat_Carrier
  * 																 	  @arg 1 : Sat_Payload
  * 																  	  @arg 2 : Ground_Sation
  * @param SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp , created object for wireless communication
  * @retval NONE
  */
void SubSys_WirelessCom_Telemetry_Transfer_From_To(MissionUnit From_X, MissionUnit To_Y, SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp){

	/*! Use it when working on Sat_Carrier flight software*/
	if(From_X == Sat_Carrier && To_Y == Sat_Payload){

		/*! Create message packet for Carrier and send to the Payload*/
		SubSys_WirelessCom_Telemetry_Create_Packet_For(Sat_Carrier, dev_WirelessComApp);

				/* 13 pairs of '<>' and 59Byte data are 75 byte as total budget*/
				Written_Bytes = sprintf(dev_WirelessComApp->Buffer.Tx,
																		"<%x><%x><%x><%.2f><%.2f><%.1f><%.1f><%.2f><%.4f><%c><%.4f><%c><%.1f>",
																		dev_WirelessComApp->Target_ADDH,
																		dev_WirelessComApp->Target_ADDL,
																		dev_WirelessComApp->Target_Ch,

																		dev_WirelessComApp->Variable.Carr_Pressure,
																		dev_WirelessComApp->Variable.Carr_Temperature,
																		dev_WirelessComApp->Variable.Carr_VertHeight,
																		dev_WirelessComApp->Variable.Carr_VertSpeed,

																		dev_WirelessComApp->Variable.Carr_BatteryVoltage,

																		dev_WirelessComApp->Variable.Carr_GPS_Latitude,
																		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Latitude,
																		dev_WirelessComApp->Variable.Carr_GPS_Longitude,
																		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Longtitude,
																		dev_WirelessComApp->Variable.Carr_GPS_Altitude);

				// SEND THE ALL DATA AS USING UART , DMA INTERRUPT (WILL BE ADDED)

	}

	/*! Use it when working on Sat_Payload flight software*/
	else if(From_X == Sat_Payload && To_Y == Sat_Carrier){
		// Will be add code blocks when will be using feedbacks
	}

	/*! Use it when working on Sat_Payload flight software*/
	else if(From_X == Sat_Payload && To_Y == GroundStation){

		/*! Create message packet for Payload and send to the Ground Station*/
		SubSys_WirelessCom_Telemetry_Create_Packet_For(Sat_Payload, dev_WirelessComApp);

				/*! 32 pairs of '<>' and 125Byte data are 189 byte as total budget*/
				Written_Bytes = sprintf(dev_WirelessComApp->Buffer.Tx,
																	"<%x><%x><%x><%u><%u><%.2f><%.2f><%.1f><%.1f><%.2f><%.4f><%c><%.4f><%c><%.1f><%.2f><%.2f><%.2f><%u><%u><%u><%u><%u><%u><%u><%u><%c><%c><%c><%c><%.1f><%.1f>",
																	dev_WirelessComApp->Target_ADDH,
																	dev_WirelessComApp->Target_ADDL,
																	dev_WirelessComApp->Target_Ch,

																	dev_WirelessComApp->Variable.TeamID,
																	dev_WirelessComApp->Variable.PacketNum,

																	dev_WirelessComApp->Variable.PayLoad_Pressure,
																	dev_WirelessComApp->Variable.PayLoad_Temperature,
																	dev_WirelessComApp->Variable.PayLoad_VertHeight,
																	dev_WirelessComApp->Variable.PayLoad_VertSpeed,


																	dev_WirelessComApp->Variable.Payload_BatteryVoltage,

																	dev_WirelessComApp->Variable.PayLoad_GPS_Latitude,
																	dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Latitude,
																	dev_WirelessComApp->Variable.PayLoad_GPS_Longitude,
																	dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Longtitude,
																	dev_WirelessComApp->Variable.PayLoad_GPS_Altitude,

																	dev_WirelessComApp->Variable.PayLoad_Roll,
																	dev_WirelessComApp->Variable.PayLoad_Pitch,
																	dev_WirelessComApp->Variable.PayLoad_Yaw,

																	dev_WirelessComApp->Variable.Payload_Second,
																	dev_WirelessComApp->Variable.Payload_Minute,
																	dev_WirelessComApp->Variable.Payload_Hour,
																	dev_WirelessComApp->Variable.Payload_Day,
																	dev_WirelessComApp->Variable.Payload_Month,
																	dev_WirelessComApp->Variable.Payload_Year,

																	dev_WirelessComApp->Variable.ErrorCode,
																	dev_WirelessComApp->Variable.SatelliteStat,

																	dev_WirelessComApp->Variable.Payload_Filter_NLNL[0],
																	dev_WirelessComApp->Variable.Payload_Filter_NLNL[1],
																	dev_WirelessComApp->Variable.Payload_Filter_NLNL[2],
																	dev_WirelessComApp->Variable.Payload_Filter_NLNL[3],
																	dev_WirelessComApp->Variable.Station_IOTdata,
																	dev_WirelessComApp->Variable.VertHeight_Diff);
				// SEND THE ALL DATA AS USING UART , DMA INTERRUPT (WILL BE ADDED)
	}

	/*! Use it when working on Sat_Station flight software*/
	else if(From_X == GroundStation && To_Y == Sat_Payload){

		/*! Create message packet for Ground Sation and send to the Payload*/
		SubSys_WirelessCom_Telemetry_Create_Packet_For(GroundStation, dev_WirelessComApp);

				/*! 9 pairs of '<>' and 9Byte data are 27 byte as total budget*/
				Written_Bytes = sprintf(dev_WirelessComApp->Buffer.Tx,
																		"<%x><%x><%x><%.1f><%u><%c><%c><%c><%c>",
																		dev_WirelessComApp->Target_ADDH,
																		dev_WirelessComApp->Target_ADDL,
																		dev_WirelessComApp->Target_Ch,

																		dev_WirelessComApp->Variable.Station_IOTdata,
																		dev_WirelessComApp->Variable.Satellite_ManuelSep,
																		dev_WirelessComApp->Variable.Ground_Filter_NLNL[0],
																		dev_WirelessComApp->Variable.Ground_Filter_NLNL[1],
																		dev_WirelessComApp->Variable.Ground_Filter_NLNL[2],
																		dev_WirelessComApp->Variable.Ground_Filter_NLNL[3]);
				// SEND THE ALL DATA AS USING UART , DMA INTERRUPT (WILL BE ADDED)

	}

}


void SubSys_WirelessCom_Telemetry_Reception_From_To(MissionUnit From_X, MissionUnit To_Y, SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp){

	if(From_X == Sat_Carrier && To_Y == Sat_Payload){ // just for  Payload



	}
	else if(From_X == Sat_Payload && To_Y == Sat_Carrier){ // just for Carrier

	}
	else if(From_X == Sat_Payload && To_Y == GroundStation){ // just for ground station

	}
	else if(From_X == GroundStation && To_Y == Sat_Payload){ // just for payload

	}
}

/**
 * @brief  : Creates 3 types packet for Carrier, Payload and Ground Station
 * @note   : Where do you want to send packet, select that, For example you are a courier and
 * 			 carry the packet to the selected home(MissionUnite x)
 *
 * @param  : MissionUnit x, Packet type used for your specific purpose @arg 0 : Sat_Carrier
 * 																	   @arg 1 : Sat_Payload
 * 																	   @arg 2 : Ground_Sation
 * @param  : SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp , created object for wireless communication
 * @retval NONE
 */
void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x,SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp){
	switch(x){

	case Sat_Carrier :

		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*! Target device will be Satellite's Payload*/
		dev_WirelessComApp->Buffer.Tx[0] = dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		/*From MS5611*/
		dev_WirelessComApp->Variable.Carr_Pressure;
		dev_WirelessComApp->Variable.Carr_Temperature;
		dev_WirelessComApp->Variable.Carr_VertHeight;
		dev_WirelessComApp->Variable.Carr_VertSpeed;

		/*From ADC*/
		dev_WirelessComApp->Variable.Carr_BatteryVoltage;

		/*From L-86GPS*/
		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Latitude;
		dev_WirelessComApp->Variable.Carr_GPS_Latitude;
		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Longtitude;
		dev_WirelessComApp->Variable.Carr_GPS_Longitude;
		dev_WirelessComApp->Variable.Carr_GPS_Altitude;

		/*! Each time a packet is generated, the count will increase by 1*/
		dev_WirelessComApp->Variable.PacketNum++;

		break;

	case Sat_Payload :

		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*!Target device will be Satellite's Ground Satation*/
		dev_WirelessComApp->Buffer.Tx[0] = dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		/*From MS5611*/
		dev_WirelessComApp->Variable.PayLoad_Pressure;
		dev_WirelessComApp->Variable.PayLoad_Temperature;
		dev_WirelessComApp->Variable.PayLoad_VertHeight;
		dev_WirelessComApp->Variable.PayLoad_VertSpeed;

		/*From ADC*/
		dev_WirelessComApp->Variable.Payload_BatteryVoltage;

		/*From L-86GPS*/
		dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Latitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Latitude;
		dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Longtitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Longitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Altitude;

		/*! Each time a packet is generated, the count will increase by 1*/
		dev_WirelessComApp->Variable.PacketNum;

		/*From BNO055 Gyro*/
		dev_WirelessComApp->Variable.PayLoad_Roll;
		dev_WirelessComApp->Variable.PayLoad_Pitch;
		dev_WirelessComApp->Variable.PayLoad_Yaw;

		/*From internal/external RTC modul*/
		dev_WirelessComApp->Variable.Payload_Second;
		dev_WirelessComApp->Variable.Payload_Minute;
		dev_WirelessComApp->Variable.Payload_Hour;
		dev_WirelessComApp->Variable.Payload_Day;
		dev_WirelessComApp->Variable.Payload_Month;
		dev_WirelessComApp->Variable.Payload_Year;

		/*From payload general algorithm*/
		dev_WirelessComApp->Variable.ErrorCode;
		dev_WirelessComApp->Variable.SatelliteStat;
		dev_WirelessComApp->Variable.TeamID;
		dev_WirelessComApp->Variable.VertHeight_Diff;

		/*From ground station*/
		dev_WirelessComApp->Variable.Payload_Filter_NLNL;
		dev_WirelessComApp->Variable.Station_IOTdata;

		break;

	case GroundStation :
		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*!Target device will be Satellite's Payload*/
		dev_WirelessComApp->Buffer.Tx[0] = dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		dev_WirelessComApp->Variable.Payload_Filter_NLNL;
		dev_WirelessComApp->Variable.Station_IOTdata;
		dev_WirelessComApp->Variable.Satellite_ManuelSep;

		break;
	}
}
