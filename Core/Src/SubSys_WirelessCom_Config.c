#include "SubSys_WirelessCom_Config.h"
#include "SubSys_WirelessCom_App.h"



void SubSys_WirelessCom_Config_Init(WirelesscomConfig_HandleTypeDef    *dev){


	dev->LORA_PIN_M0 = GPIO_PIN_13;
	dev->LORA_PIN_M1 = GPIO_PIN_14;

	SubSys_WirelessCom_Config_CNFG_MODE(dev);


	dev->param.SerialPortRate = UART_Rate_is_1200;
	dev->param.AirDataRate    = Air_Data_Rate_2d_4k;
	/*Keep going on , write other parameters*/

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

	switch(dev->param.Mode_SW){

		case NormalMode :	/*! UART and wireless channel areopen, transparent transmission is on */
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M0, GPIO_PIN_RESET);
		break;

		case WORsending :	/*!WOR Transmitter (it sends packet in every period)*/
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M1, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M0, GPIO_PIN_SET);
		break;

		case WORreceiving :	/*!WOR Receiver (it sends packet in every period)*/
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M0, GPIO_PIN_RESET);
		break;

		case DeepSleep :	/*! Module goes to sleep (automatically wake up when configuring parameters*/
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M1, GPIO_PIN_SET);
			HAL_GPIO_WritePin(dev->GPIOx, dev->LORA_PIN_M0, GPIO_PIN_SET);
		break;

	}

}
