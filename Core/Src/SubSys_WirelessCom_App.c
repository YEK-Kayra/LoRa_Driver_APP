
/**
   	(+) Non-Blocking mode: The communication is performed using Interrupts
           or DMA, these API's return the HAL status.
           The end of the data processing will be indicated through the
           dedicated UART IRQ when using Interrupt mode or the DMA IRQ when
           using DMA mode.
           The HAL_UART_TxCpltCallback(), HAL_UART_RxCpltCallback() user callbacks
           will be executed respectively at the end of the transmit or receive process
           The HAL_UART_ErrorCallback()user callback will be executed when a communication error is detected.

	(#) Non-Blocking mode API's with DMA are :
			(+) HAL_UART_Transmit_DMA()
			(+) HAL_UART_Receive_DMA()
			(+) HAL_UART_DMAPause()
			(+) HAL_UART_DMAResume()
			(+) HAL_UART_DMAStop()

	(#) A set of Transfer Complete Callbacks are provided in Non_Blocking mode:
			(+) HAL_UART_TxHalfCpltCallback()
			(+) HAL_UART_TxCpltCallback()
			(+) HAL_UART_RxHalfCpltCallback()
			(+) HAL_UART_RxCpltCallback()
			(+) HAL_UART_ErrorCallback()

 */
#include "SubSys_WirelessCom_App.h"


void SubSys_WirelessCom_Telemetry_Create_Packet_For(MissionUnit x){

	switch(x){

	case Sat_Carrier :
		//will be added
		break;
	case Sat_Payload :
		//will be added
		break;




	}

}




