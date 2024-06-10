

#ifndef INC_SUBSYS_WIRELESSCOM_APP_H_
#define INC_SUBSYS_WIRELESSCOM_APP_H_

#include "SubSys_WirelessCom_Config.h"


/******************************************************************************
         				#### WIRELESSCOM ENUMS ####
******************************************************************************/
typedef enum{

	Sat_Carrier,
	Sat_Payload,
	GroundStation

}MissionUnit;


/******************************************************************************
         				#### WIRELESSCOM PROTOTYPES OF FUNCTIONS ####
******************************************************************************/

//oluşturulan paketi x diye girilen(taşıyıcı , görev yükü , istasyon) a gönderecek
void SubSys_WirelessCom_Telemetry_Transfer_To(MissionUnit x);

//oluşturulan paketi x diye girilen(taşıyıcı , görev yükü , istasyon)dan alacak
void SubSys_WirelessCom_Telemetry_Reception_From(MissionUnit x);

//hangi cihazda bulunuyorsa neresi için görev yapacaksa ora için telemetri paketi oluşturacak
void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x);





#endif /* INC_SUBSYS_WIRELESSCOM_APP_H_ */
