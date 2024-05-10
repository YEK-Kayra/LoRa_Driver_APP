#include "SubSys_WirelessCom_Config.h"
#include "SubSys_WirelessCom_App.h"



void SubSys_WirelessCom_Config_Init(WirelesscomConfig_HandleTypeDef    *dev){

	dev->param.SerialPortRate = UART_Rate_is_1200;


	dev->ADDH = 0xCC;
	dev->ADDL = 0xCC;

	dev->REG0 = ((dev->param.SerialPortRate << 5) | (dev->param.ParityBit  << 3) | (dev->param.AirDataRate  << 0));
	dev->REG1 = ((dev->param.SubPacket << 6) | (dev->param.AmbientNoise_SW  << 5) | (dev->param.TX_Power  << 0));
	dev->REG2 = (dev->param.dev_Channel << 0);
	dev->REG3 = ((dev->param.RSSIByte_SW << 7) | (dev->param.TransmissionMethod << 6) | (dev->param.LBT_SW << 4) | (dev->param.WorCycle << 0));

	dev->REG_CRYPT_H = 0;
	dev->REG_CRYPT_L = 0;
}


void SubSys_WirelessCom_Config_SET_REG(WirelesscomConfig_HandleTypeDef   *dev){

}


void SubSys_WirelessCom_Config_READ_REG(WirelesscomConfig_HandleTypeDef    *dev){

}


void SubSys_WirelessCom_Config_CNFG_MODE(WirelesscomConfig_HandleTypeDef    *dev){

}
