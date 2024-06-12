#include "SubSys_WirelessCom_App.h"


void SubSys_WirelessCom_Telemetry_Transfer_From_To(MissionUnit From_X, MissionUnit To_Y){

	if(From_X == Sat_Carrier && To_Y == Sat_Payload){ // just for Carrier

	}
	else if(From_X == Sat_Payload && To_Y == Sat_Carrier){ //just for Payload

	}
	else if(From_X == Sat_Payload && To_Y == GroundStation){ // just for payload

	}
	else if(From_X == GroundStation && To_Y == Sat_Payload){ //  just for ground station

	}
}


void SubSys_WirelessCom_Telemetry_Reception_From_To(MissionUnit From_X, MissionUnit To_Y){

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
 * @brief  : Creates 3 types packet for Carrier, Payload and ground station
 * @note   : Where do you want to send packet, select that, You are a courier and
 * 			 carry the packet to the selected home(MissionUnite x)
 *
 * @param  : MissionUnit x, Packet type used for your specific purpose
 */
void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x,SubSys_WirelessCom_APP_HandleTypeDef *dev_WirelessComApp){
	switch(x){

	//ev sahibi taşıyıcı olcak fixed adresi ise payload olcak
	case Sat_Carrier :

		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*!Target device will be Satellite's Payload*/
		dev_WirelessComApp->Buffer.Tx[0] = (char)dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = (char)dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = (char)dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		//From MS5611
		dev_WirelessComApp->Variable.Carr_Pressure;
		dev_WirelessComApp->Variable.Carr_Temperature;
		dev_WirelessComApp->Variable.Carr_VertHeight;
		dev_WirelessComApp->Variable.Carr_VertSpeed;
		//From ADC
		dev_WirelessComApp->Variable.Carr_BatteryVoltage;
		//From L-86GPS
		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Latitude;
		dev_WirelessComApp->Variable.Carr_GPS_Latitude;
		dev_WirelessComApp->Variable.Carr_GPS_CompassWay_Longtitude;
		dev_WirelessComApp->Variable.Carr_GPS_Longitude;
		dev_WirelessComApp->Variable.Carr_GPS_Altitude;

		//Each time a packet is generated, the count will increase by 1
		dev_WirelessComApp->Variable.PacketNum++;

		break;

	case Sat_Payload :
		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*!Target device will be Satellite's Ground Satation*/
		dev_WirelessComApp->Buffer.Tx[0] = (char)dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = (char)dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = (char)dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		//From MS5611
		dev_WirelessComApp->Variable.PayLoad_Pressure;
		dev_WirelessComApp->Variable.PayLoad_Temperature;
		dev_WirelessComApp->Variable.PayLoad_VertHeight;
		dev_WirelessComApp->Variable.PayLoad_VertHeight;

		//From ADC
		dev_WirelessComApp->Variable.Payload_BatteryVoltage;

		//From L-86GPS
		dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Latitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Latitude;
		dev_WirelessComApp->Variable.Payload_GPS_CompassWay_Longtitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Longitude;
		dev_WirelessComApp->Variable.PayLoad_GPS_Altitude;

		//Each time a packet is generated, the count will increase by 1
		dev_WirelessComApp->Variable.PacketNum;

		//From BNO055 Gyro
		dev_WirelessComApp->Variable.PayLoad_Roll;
		dev_WirelessComApp->Variable.PayLoad_Pitch;
		dev_WirelessComApp->Variable.PayLoad_Yaw;

		//From internal/external RTC modul
		dev_WirelessComApp->Variable.Payload_Second;
		dev_WirelessComApp->Variable.Payload_Minute;
		dev_WirelessComApp->Variable.Payload_Hour;
		dev_WirelessComApp->Variable.Payload_Day;
		dev_WirelessComApp->Variable.Payload_Month;
		dev_WirelessComApp->Variable.Payload_Year;

		//From payload general algorithm
		dev_WirelessComApp->Variable.ErrorCode;
		dev_WirelessComApp->Variable.SatelliteStat;
		dev_WirelessComApp->Variable.TeamID;

		//From ground station
		dev_WirelessComApp->Variable.Payload_Filter_NLNL;
		dev_WirelessComApp->Variable.Station_IOTdata;

		break;

	case GroundStation :
		/*-------------TARGET DEVICE ADDRESS AND CHANNEL INFO----------------*/
		/*!Target device will be Satellite's Payload*/
		dev_WirelessComApp->Buffer.Tx[0] = (char)dev_WirelessComApp->Target_ADDH;
		dev_WirelessComApp->Buffer.Tx[1] = (char)dev_WirelessComApp->Target_ADDL;
		dev_WirelessComApp->Buffer.Tx[2] = (char)dev_WirelessComApp->Target_Ch;

		/*-------------YOUR DEVICE VARIABLE THAT YOU WİLL SEND----------------*/ /*Note : Will be system variable opposite to variables*/
		dev_WirelessComApp->Variable.Payload_Filter_NLNL;
		dev_WirelessComApp->Variable.Station_IOTdata;
		dev_WirelessComApp->Variable.Satellite_ManuelSep;

		break;
	}
}
