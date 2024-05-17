#include "SubSys_WirelessCom_Config.h"
#include "SubSys_WirelessCom_App.h"

/*! Is filled by lora's parameter variables at SubSys_WirelessCom_Config_Init function*/
uint8_t ParamsLora[11];

void SubSys_WirelessCom_Config_Init(WirelesscomConfig_HandleTypeDef    *dev){



	/*! Upload selected mode */
	SubSys_WirelessCom_Config_CNFG_MODE(dev);

	/*! Select parameters */
	dev->param.SerialPortRate 		= UART_Rate_is_1200;
	dev->param.ParityBit 			= p8N1;
	dev->param.AirDataRate    		= Air_Data_Rate_2d_4k;

	dev->param.SubPacket 			= bytes_200;
	dev->param.AmbientNoise_SW 		= EnableFea;
	dev->param.TX_Power 			= dBm30;

	dev->param.dev_Channel 			= 0x12;

	dev->param.LBT_SW 				= EnableFea;
	dev->param.TransmissionMethod 	= Fixed_t ;
	dev->param.RSSIByte_SW 			= EnableFea ;
	dev->param.WorCycle 			= ms500;


	/*! Save parameters into the "dev" object */
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

	uint8_t cnt = 0;

	/*! Save register variables into the ParamsLora array for sending lora chip at once*/
	ParamsLora[cnt] = writeCmnd; 			cnt++;		/* Command name */
	ParamsLora[cnt] = BaseAddress; 			cnt++;		/* Starting addres */
	ParamsLora[cnt] = sizeof(ParamsLora); 	cnt++; 		/* Size of written bytes */
	ParamsLora[cnt] = dev->ADDH ; 			cnt++; 		/* Addres High byte*/
	ParamsLora[cnt] = dev->ADDL; 			cnt++;		/* Addres Low byte */
	ParamsLora[cnt] = dev->REG0; 			cnt++;		/* Parameter register values*/
	ParamsLora[cnt] = dev->REG1; 			cnt++;
	ParamsLora[cnt] = dev->REG2; 			cnt++;
	ParamsLora[cnt] = dev->REG3; 			cnt++;
	ParamsLora[cnt] = dev->REG_CRYPT_H; 	cnt++;
	ParamsLora[cnt] = dev->REG_CRYPT_L; 	cnt++;


HAL_UART_Receive_DMA(dev->huart, ParamsLora, sizeof(ParamsLora));

HAL_UART_Receive_DMA(dev->huart, pData, Size)
}


void SubSys_WirelessCom_Config_READ_REG(WirelesscomConfig_HandleTypeDef    *dev){

}


void SubSys_WirelessCom_Config_CNFG_MODE(WirelesscomConfig_HandleTypeDef    *dev){

	/*! GPIO_PIN_X x can be change by user*/
	dev->LORA_PIN_M0 = GPIO_PIN_13;
	dev->LORA_PIN_M1 = GPIO_PIN_14;

	switch(dev->Mode_SW){

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
