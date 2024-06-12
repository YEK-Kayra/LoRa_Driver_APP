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

void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x){
	switch(x){

	case Sat_Carrier :
		break;
	case Sat_Payload :
		break;
	case GroundStation :
		break;

	}
}
