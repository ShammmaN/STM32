/*
 * EasyModBus.c
 *
 *  Created on: Apr 26, 2022
 *      Author: elekt
 */

 #include "EasyModBus.h"

/*
 *
 * Funkcje MODBUS zaimplementowane w freeModbus
 * 0x01	Read Coils (odczyt wyjść bitowych)
 * 0x02	Read Discrete Inputs (odczyt wejść bitowych)
 * 0x03	Read Holding Registers (odczyt n rejestrów)
 * 0x04	Read Input Register (odczyt n rejestrów wejściowych)
 * 0x05	Write Single Coil (zapis 1 bitu)
 * 0x06	Write Single Register (zapis 1 rejestru)
 * 0x0F	Write Multiple Coils (zapis n bitów)
 * 0x10	Write Multiple Registers(zapis n rejestrów)
 * 0x11	Report Slave ID (identyfikacja urządzenia slave)
 * 0x16 Write Register
 * 0x17	Read/Write Multiple Registers
 *
 *
 * 							RAMKA DANYCH Z BITAMI PARZYSTOŚCI
 * START	BIT 1	BIT 2	BIT 3	BIT 4	BIT 5	BIT 6	BIT 7	BIT 8	PARITY	STOP
 *
 * 							RAMKA DANYCH BEZ BITU PARZYSTOŚCI
 * START	BIT 1	BIT 2	BIT 3	BIT 4	BIT 5	BIT 6	BIT 7	BIT 8	STOP	STOP
 *
 *
 *
 * Każdą wiadomość rozpoczyna i kończy tzw. cisza na łączu.
 * Jest to czas bezczynności trwający 3,5 x czas pojedynczego znaku.
 * Cała ramka musi być transmitowana w sposób ciągły.
 * Pomiędzy znakami tworzącymi ramkę nie może być większy odstęp niż 1,5 x długość pojedynczego znaku.
 *
 * 1	01h	Odczyt wyjść bitowych
 * 2	02h	Odczyt wejść bitowych
 * 3	03h	Odczyt rejestrów
 * 4	04h	Odczyt rejestrów wejściowych
 * 5	05h	Zapis pojedynczego bitu
 * 6	06h	Zapis pojedynczego rejestru
 * 7	07h	Odczyt statusu urządzenia slave
 * 8	08h	Test diagnostyczny
 * 15	0Fh	Zapis bitów
 * 16	10h	Zapis rejestrów
 * 17	11h	Identyfikcja urządzenia slave
 * 128 – 255	80h – FFh	Odpowiedzi wyjątkowe
 * /
 *
 *
 *
 *
 */

void ModBus(ModBUS_Struct *ModBus, uint8_t* ModBusData){

	if(ModBusData[0] == Device_Address){
		ModBus->Slave_Addr = Device_Address;
		ModBus->Command = ModBusData[1];
		ModBus->Register = ModBusData[2];
		ModBus->Data = ModBusData[3];
		ModBus->Control = ModBusData[4];


		switch(ModBus->Command){


//		01h	Odczyt wyjść bitowych
		case 0x01 :
			ReadBinOutput();
			break;


//		02h	Odczyt wejść bitowych
		case 0x02:
			ReadBinInput();
			break;


// 		03h	Odczyt rejestrów

		case 0x03:
			ReadRegister();
			break;


//		04h Odczyt rejestrów wejściowych
		case 0x04:
			ReadRegisterInput();
			break;


//		05h	Zapis pojedynczego bitu
		case 0x05:
			WriteBit();
			break;


//		06h	Zapis pojedynczego rejestru
		case 0x06:
			WriteRegister();
			break;


//		07h	Odczyt statusu urządzenia slave
		case 0x07:
			ReadStatus();
			break;


//		08h	Test diagnostyczny
		case 0x08:
			DiagnosticTest();
			break;


//	    0Fh	Zapis bitów
		case 0x0F:
			WriteBit();
			break;


//		10h	Zapis rejestrów
		case 0x10:
			WriteRegister();
			break;


//		11h	Identyfikcja urządzenia slave
		case 0x11:
			WhoIAm();
			break;


//		16h	Zapis rejestrów
		case 0x16:
			WriteRegister();
			break;


//		17h	Write Multiple Registers
		case 0x17:
			WriteRegisterMultiple();
			break;



		}

	}
}

//	01h	Odczyt wyjść bitowych
void ReadBinOutput(void){

}


//	02h	Odczyt wejść bitowych
void ReadBinInput(void){

}


//	03h	Odczyt rejestrów
void ReadRegister(void){

}


//	04h	Odczyt rejestrów wejściowych
void ReadRegisterInput(void){

}


//	05h	Zapis pojedynczego bitu
void WriteBit(void){

}


//	06h	Zapis pojedynczego rejestru
void WriteSingleRegister(void){

}


//	07h	Odczyt statusu urządzenia slave
void ReadStatus(void){

}


//	08h	Test diagnostyczny
void DiagnosticTest(void){

}


//  0Fh	Zapis bitów
void WriteBitMultiple(void){

}



//	11h	Identyfikcja urządzenia slave
void WhoIAm(void){

}


//	16h	Zapis rejestrów
void WriteRegister(void){

}


//	17h	Write Multiple Registers
void WriteRegisterMultiple(void){

}







void ModBus_Transmit(ModBUS_Struct *ModBus , ModBUS_Recive_Struct *ModBudRecive){

//	uint8_t data = 0b0011;
//	HAL_UART_Transmit_DMA(&huart6, &data, 1);
//	CDC_Transmit_FS(&data, 1);
//
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->Slave_Addr, 1);
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->Command, 1);
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->Data, 1);
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->Control, 1);
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->CR, 1);
//	HAL_UART_Transmit_DMA(&huart2, &ModBus->LF, 1);
//
//
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->Slave_Addr, 1);
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->Command, 1);
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->Data, 1);
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->Control, 1);
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->CR, 1);
//	HAL_UART_Recive_DMA(&huart2, &ModBudRecive->LF, 1);
//
//	if( ModBus->Slave_Addr == ModBudRecive)
//	{
//		if( ModBus-> Command == ModBudRecive->Command)
//		{
//			if( ModBus->Data == ModBudRecive->Data){
//
//			}
//		}
//	}





}


void ModBus_Recive(){


}



