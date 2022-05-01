/*
 * EasyModBus.h
 *
 *  Created on: Apr 26, 2022
 *      Author: elekt
 */

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



#ifndef INC_EASYMODBUS_H_
#define INC_EASYMODBUS_H_

#include "Delay.h"
#include "stm32f4xx.h"
#include "usart.h"


#define Device_Address 0x01


typedef struct
{
	uint8_t Slave_Addr;
	uint8_t Command;
	uint8_t Register;
	uint8_t Data;
	uint8_t Control;
}ModBUS_Struct;

typedef struct
{
	uint8_t Slave_Addr;
	uint8_t Command;
	uint8_t Data;
	uint8_t Control;
	uint8_t CR;
	uint8_t LF;
}ModBUS_Recive_Struct;


void ModBus(ModBUS_Struct *ModBus, uint8_t* ModBusData);
void ModBus_Transmit(ModBUS_Struct *ModBus, ModBUS_Recive_Struct *ModBusRec);
void ModBus_Recive(void);

//	01h	Odczyt wyjść bitowych
void ReadBinOutput(void);
//	02h	Odczyt wejść bitowych
void ReadBinInput(void);
//	03h	Odczyt rejestrów
void ReadRegister(void);
//	04h	Odczyt rejestrów wejściowych
void ReadRegisterInput(void);
//	05h	Zapis pojedynczego bitu
void WriteBit(void);
//	06h	Zapis pojedynczego rejestru
void WriteSingleRegister(void);
//	07h	Odczyt statusu urządzenia slave
void ReadStatus(void);
//	08h	Test diagnostyczny
void DiagnosticTest(void);
//  0Fh	Zapis bitów
void WriteBitMultiple(void);
//	11h	Identyfikcja urządzenia slave
void WhoIAm(void);
//	16h	Zapis rejestrów
void WriteRegister(void);
//	17h	Write Multiple Registers
void WriteRegisterMultiple(void);



#endif /* INC_EASYMODBUS_H_ */
