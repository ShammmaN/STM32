/*
 * LSM303DLHC.h
 *
 *  Created on: 19 cze 2022
 *      Author: shammman
 */

#ifndef INC_LSM303DLHC_H_
#define INC_LSM303DLHC_H_



#endif /* INC_LSM303DLHC_H_ */



/* Default address od sensor is
Read 0011110 1 00111101 (3Dh)
Write 0011110 0 00111100 (3Ch)	*/
#define SENSOR_READ		0x3D
#define SENSOR_WRITE	0x3C

#include "stm32f4xx.h"

typedef struct
{
 uint8_t CTRL_REG1;
 uint8_t CTRL_REG2;
 uint8_t CTRL_REG3;
 uint8_t CTRL_REG4;
 uint8_t CTRL_REG5;
 uint8_t CTRL_REG6;
 uint8_t REFERENCE;
 uint8_t STATUS_REG;
 uint8_t FIFO_CTRL_REG;
 uint8_t INT1_CFG;
 uint8_t INT1_SRC;
 uint8_t INT1_THS;
 uint8_t INT1_DURATION;
 uint8_t INT2_CFG;
 uint8_t INT2_SRC;
 uint8_t INT2_THS;
 uint8_t INT2_DURATION;
 uint8_t CLICK_CFG;
 uint8_t CLICK_SRC;
 uint8_t CLICK_THS;
 uint8_t TIME_LIMIT;
 uint8_t TIME_LATENCY;
 uint8_t TIME_WINDOW;
}LSM303DLHC_TypeDef;

/*
 * Memory map of sensor
 */

////////////////////			Linear acceleration register description 		////////////////

#define CTRL_REG1_A 	0x20 		//RW Default 00000111
#define CTRL_REG2_A 	0x21		//RW Default 00000000
#define CTRL_REG3_A 	0x22 		//RW Default 00000000
#define CTRL_REG4_A 	0x23 		//RW Default 00000000
#define CTRL_REG5_A 	0x24 		//RW Default 00000000
#define CTRL_REG6_A 	0x25 		//RW Default 00000000
#define REFERENCE_A 	0x26		//RW Reference value for interrupt generation. Default value: 0000 0000
#define STATUS_REG_A 	0x27		//R Default 00000000
#define OUT_X_L_A 		0x28		//R Default output 	X-axis acceleration data. The value is expressed in two’s complement.
#define OUT_X_H_A 		0x29		//R Default output	X-axis acceleration data. The value is expressed in two’s complement.
#define OUT_Y_L_A 		0x2A		//R Default output	Y-axis acceleration data. The value is expressed in two’s complement.
#define OUT_Y_H_A 		0x2B		//R Default output	Y-axis acceleration data. The value is expressed in two’s complement.
#define OUT_Z_L_A 		0x2C		//R Default output	Z-axis acceleration data. The value is expressed in two’s complement.
#define OUT_Z_H_A 		0x2D		//R Default output	Z-axis acceleration data. The value is expressed in two’s complement.
#define FIFO_CTRL_REG_A 0x2E		//RW Default 00000000
#define FIFO_SRC_REG_A  0x2F		//R
#define INT1_CFG_A 		0x30		//RW Default 00000000
#define INT1_SRC_A 		0x31		//R Default 00000000
#define INT1_THS_A 		0x32		//RW Default 00000000
#define INT1_DURATION_A 0x33		//RW Default 00000000
#define INT2_CFG_A 		0x34		//RW Default 00000000
#define INT2_SRC_A 		0x35		//R Default 00000000
#define INT2_THS_A 		0x36		//RW Default 00000000
#define INT2_DURATION_A 0x37		//RW Default 00000000
#define CLICK_CFG_A 	0x38		//RW Default 00000000
#define CLICK_SRC_A 	0x39		//RW Default 00000000
#define CLICK_THS_A 	0x3A		//RW Default 00000000
#define TIME_LIMIT_A	0x3B		//RW Default 00000000
#define TIME_LATENCY_A	0x3C		//RW Default 00000000
#define TIME_WINDOW_A	0x3D		//RW Default 00000000







////////////////////			CTRL_REG1_A description			////////////////////////////

#define CTRL_REG1_Xen		(1U<<0)		// X-axis enable. Default value: 1  (0: X-axis disabled, 1: X-axis enabled)
#define CTRL_REG1_Yen		(1U<<1)		// Y-axis enable. Default value: 1  (0: Y-axis disabled, 1: Y-axis enabled)
#define CTRL_REG1_Zen		(1U<<2)		// Z-axis enable. Default value: 1 (0: Z-axis disabled, 1: Z-axis enabled)
#define CTRL_REG1_LPen		(1U<<3)		// Low-power mode enable. Default value: 0 (0: normal mode, 1: low-power mode)
#define CTRL_REG1_PD		(0x00<<4)	// Power-down mode
#define CTRL_REG1_1Hz		(0x01<<4)	// Normal / low-power mode (1 Hz)
#define CTRL_REG1_10Hz		(0x02<<4)	// Normal / low-power mode (10 Hz)
#define CTRL_REG1_25Hz		(0x03<<4)	// Normal / low-power mode (25 Hz)
#define CTRL_REG1_50Hz		(0x04<<4)	// Normal / low-power mode (50 Hz)
#define CTRL_REG1_100Hz		(0x05<<4)	// Normal / low-power mode (100 Hz)
#define CTRL_REG1_200Hz		(0x06<<4)	// Normal / low-power mode (200 Hz)
#define CTRL_REG1_400Hz		(0x07<<4)	// Normal / low-power mode (400 Hz)
#define CTRL_REG1_LPmode	(0x08<<4)	// Low-power mode (1.620 kHz)
#define CTRL_REG1_Normal	(0x09<<4)	// Normal (1.344 kHz) / low-power mode (5.376 kHz)
//////////////////////////////////////////////////////////////////////////////////////////////







////////////////////			CTRL_REG2_A description			////////////////////////////

//High-pass filter mode configuration//
#define CTRL_REG2_HPM_NORMAL	 (0x0<<6) // Normal mode (reset reading HP_RESET_FILTER)
#define CTRL_REG2_HPM_REF_SIG	 (0x1<<6) // Reference signal for filtering
#define CTRL_REG2_HPM_NORMALMODE (0x2<<6) // Normal mode
#define CTRL_REG2_HPM_AUTORES    (0x3<<6) // Autoreset on interrupt event

#define CTRL_REG2_HPCF			(0X3<<4) // High-pass filter cutoff frequency selection
#define CTRL_REG2_FDS			(1U<<3)	 // Filtered data selection. Default value: 0 (0: internal filter bypassed, 1: data from internal filter sent to output register and FIFO)
#define CTRL_REG2_HPCLICK		(1U<<2)	 // high-pass filter enabled for click function (0: filter bypassed, 1: filter enabled)
#define CTRL_REG2_HPIS2			(1U<<1)	 // High-pass filter enabled for AOI function on Interrupt 2 (0: filter bypassed, 1: filter enabled)
#define CTRL_REG2_HPIS1			(1U<<0)	 // High-pass filter enabled for AOI function on Interrupt 1 (0: filter bypassed, 1: filter enabled)
//////////////////////////////////////////////////////////////////////////////////////////////







////////////////////			CTRL_REG3_A description			///////////////////////////////

#define CTRL_REG3_I1_OVERRUN	(1U<<0)		// FIFO overrun interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_WTM		(1U<<1)		// FIFO watermark interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_DRDY2		(1U<<2)		// DRDY2 interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_DRDY1		(1U<<3)		// DRDY1 interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_AOI2		(1U<<4)		// AOI2 interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_AOI1		(1U<<5)		// AOI1 interrupt on INT1. Default value 0 (0: disable, 1: enable)
#define CTRL_REG3_I1_CLICK		(1U<<6)		// CLICK interrupt on INT1. Default value 0 (0: disable, 1: enable)
//////////////////////////////////////////////////////////////////////////////////////////////






////////////////////			CTRL_REG4_A description			///////////////////////////////

#define CTRL_REG4_SIM		(1U<<0)		//  SPI serial interface mode selection. Default value: 0 (0: 4-wire interface, 1: 3-wire interface).
#define CTRL_REG4_HR		(1U<<3)		// High-resolution output mode: Default value: 0 (0: high-resolution disable, 1: high-resolution enable)
#define CTRL_REG4_FS_2G		(0x0<<4)		// Full-scale selection. Default value: 00 (00: ±2 g, 01: ±4 g, 10: ±8 g, 11: ±16 g)
#define CTRL_REG4_FS_4G 	(0x1<<4)		// Full-scale selection. Default value: 00 (00: ±2 g, 01: ±4 g, 10: ±8 g, 11: ±16 g)
#define CTRL_REG4_FS_8G		(0x2<<4)		// Full-scale selection. Default value: 00 (00: ±2 g, 01: ±4 g, 10: ±8 g, 11: ±16 g)
#define CTRL_REG4_FS_11 	(0x2<<4)		// Full-scale selection. Default value: 00 (00: ±2 g, 01: ±4 g, 10: ±8 g, 11: ±16 g)
#define CTRL_REG4_BLE		(1U<<6)		// Big/little endian data selection. Default value 0. (0: data LSB @ lower address, 1: data MSB @ lower address)
#define CTRL_REG4_BDU		(1U<<7)		// Block data update. Default value: 0 (0: continuous update, 1: output registers not updated until MSB and LSB have been read




////////////////////			CTRL_REG5_A description			//////////////////////////////

#define CTRL_REG5_D4D_INT2		(1U<<0)		// 4D enable: 4D detection is enabled on INT2 when 6D bit on INT2_CFG is set to 1.
#define CTRL_REG5_LIR_INT2		(1U<<1)		// Latch interrupt request on INT2_SRC register, with INT2_SRC register cleared by reading INT2_SRC itself. Default value: 0. (0: interrupt request not latched, 1: interrupt request latched)
#define CTRL_REG5_D4D_INT1		(1U<<2)		// 4D enable: 4D detection is enabled on INT1 when 6D bit on INT1_CFG is set to 1.
#define CTRL_REG5_LIR_INT1		(1U<<3)		// Latch interrupt request on INT1_SRC register, with INT1_SRC register cleared by reading INT1_SRC itself. Default value: 0. (0: interrupt request not latched, 1: interrupt request latched)
#define CTRL_REG5_FIFO_EN		(1U<<6)		// FIFO enable. Default value: 0 (0: FIFO disable, 1: FIFO enable)
#define CTRL_REG5_BOOT			(1U<<7)		// Reboot memory content. Default value: 0 (0: normal mode, 1: reboot memory content)
//////////////////////////////////////////////////////////////////////////////////////////////




////////////////////			CTRL_REG6_A description			///////////////////////////////

#define CTRL_REG6_H_LACTIVE		(1U<<1)		// Interrupt active high, low. Default value 0. (0: active high, 1: active low)
#define CTRL_REG6_P2_ACT		(1U<<3)		// Active function status on PAD2. Default value 0 (0: disable, 1: enable)
#define CTRL_REG6_BOOT_I1		(1U<<4)	// Reboot memory content on PAD2. Default value: 0 (0: disable, 1: enable)
#define CTRL_REG6_I2_INT2		(1U<<5)	// Interrupt 2 on PAD2. Default value 0. (0: disable, 1: enable)
#define CTRL_REG6_I2_INT1		(1U<<6)	// Interrupt 1 on PAD2. Default value 0. (0: disable, 1: enable)
#define CTRL_REG6_I2_CLICKen	(1U<<7)		// CLICK interrupt on PAD2. Default value 0. (0: disable, 1: enable)
//////////////////////////////////////////////////////////////////////////////////////////////




////////////////////			STATUS_REG_A description			///////////////////////////

#define STATUS_REG_XDA		(1U<<0)		// X-axis new data available. Default value: 0 (0: new data for the X-axis is not yet available, 1: new data for the X-axis is available)
#define STATUS_REG_YDA		(1U<<1)		// Y-axis new data available. Default value: 0 (0: new data for the Y-axis is not yet available, 1: new data for the Y-axis is available)
#define STATUS_REG_ZDA		(1U<<2)		// Z-axis new data available. Default value: 0 (0: new data for the Z-axis is not yet available, 1: new data for the Z-axis is available)
#define STATUS_REG_ZYXDA	(1U<<3)		// X-, Y-, and Z-axis new data available. Default value: 0 (0: a new set of data is not yet available, 1: a new set of data is available)
#define STATUS_REG_XOR		(1U<<4)		// X-axis data overrun. Default value: 0 (0: no overrun has occurred, 1: new data for the X-axis has overwritten the previous data)
#define STATUS_REG_YOR		(1U<<5)		// Y-axis data overrun. Default value: 0 (0: no overrun has occurred, 1: new data for the Y-axis has overwritten the previous data)
#define STATUS_REG_ZOR		(1U<<6)		//Z-axis data overrun. Default value: 0 (0: no overrun has occurred, 1: new data for the Z-axis has overwritten the previous data
#define STATUS_REG_ZYXOR	(1U<<7)		//X-, Y-, and Z-axis data overrun. Default value: 0  (0: no overrun has occurred, 1: a new set of data has overwritten the previous data)
//////////////////////////////////////////////////////////////////////////////////////////////




////////////////////			REFERENCE_A description			//////////////////////////////
/*
 * 		REF[7:0] -> Reference value for interrupt generation. Default value: 0000 0000
 * */
#define REFERENCE_REF0		(1U<<0)		//
#define REFERENCE_REF1		(1U<<3)		//
#define REFERENCE_REF2		(0x0<<4)	//
#define REFERENCE_REF3		(0x1<<4)	//
#define REFERENCE_REF4		(0x2<<4)	//
#define REFERENCE_REF5		(1U<<6)		//
#define REFERENCE_REF6		(1U<<7)		//
#define REFERENCE_REF6		(1U<<7)		//
//////////////////////////////////////////////////////////////////////////////////////////////




////////////////////			FIFO_CTRL_REG_A description			//////////////////////////

#define FIFO_CTRL_REG_FTH0			(1U<<0)		// Default FTH value: 00000
#define FIFO_CTRL_REG_FTH1			(1U<<1)		// Default FTH value: 00000
#define FIFO_CTRL_REG_FTH2			(1U<<2)		// Default FTH value: 00000
#define FIFO_CTRL_REG_FTH3			(1U<<3)		// Default FTH value: 00000
#define FIFO_CTRL_REG_FTH4			(1U<<4)		// Default FTH value: 00000
#define FIFO_CTRL_REG_TR			(1U<<5)		// Trigger selection. Default value: 0 0: trigger event linked to trigger signal on INT1 1: trigger event linked to trigger signal on INT2
#define FIFO_CTRL_REG_BYPASS_MODE	(0X0<<6)	// Bypass mode
#define FIFO_CTRL_REG_FIFO_MODE		(0X1<<6)	// FIFO mode
#define FIFO_CTRL_REG_STREAM_MODE	(0X2<<6)	// Stream mode
#define FIFO_CTRL_REG_TRIGGER_MODE	(0X3<<6)	// Trigger mode





////////////////////			INT1_CFG_A description			///////////////////////////////

/*
 * 		AOI		6D		Interrupt mode
 * 		0		0		OR combination of interrupt events
 * 		0		1		6-direction movement recognition
 * 		1		0		AND combination of interrupt events
 * 		1		1		6-direction position recognition
 *
 *
 * 		Difference between AOI-6D = ‘01’ and AOI-6D = ‘11’.
 * 		AOI-6D = ‘01’ is movement recognition. An interrupt is generated when the orientation
 * 		moves from an unknown zone to a known zone. The interrupt signal remains for a duration
 * 		ODR.
 * 		AOI-6D = ‘11’ is direction recognition. An interrupt is generated when the orientation is
 * 		inside a known zone. The interrupt signal stays until the orientation is inside the zone.
 */
#define INT1_CFG_XDOWNE		(1U<<0)		// Enable interrupt generation on X low event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request.)
#define INT1_CFG_XUPE		(1U<<1)		// Enable interrupt generation on X high event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request.)
#define INT1_CFG_YDOWNE		(1U<<2)		// Enable interrupt generation on Y low event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request.)
#define INT1_CFG_YUPE		(1U<<3)		// Enable interrupt generation on Y high event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request.)
#define INT1_CFG_ZDOWNE		(1U<<4)		// Enable interrupt generation on Z low event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request)
#define INT1_CFG_ZUPE		(1U<<5)		// Enable interrupt generation on Z high event or on direction recognition. Default value: 0 (0: disable interrupt request, 1: enable interrupt request)
#define INT1_CFG_6D			(1U<<6)		// 6-direction detection function enabled. Default value: 0 (refer to Table 42)
#define INT1_CFG_AOI		(1U<<7)		// AND/OR combination of interrupt events. Default value: 0 (refer to Table 42)







////////////////////			INT1_SRC_A description			////////////////////////////////

/*
 * Interrupt 1 source register. Read-only register.
 * Reading at this address clears the INT1_SRC IA bit (and the interrupt signal on the INT 1
 * pin) and allows the refresh of data in the INT1_SRC register if the latched option was chosen.
 */
#define INT1_SRC_XL		(1U<<0)		// X low. Default value: 0 (0: no interrupt, 1: X low event has occurred)
#define INT1_SRC_XH		(1U<<1)		// X high. Default value: 0 (0: no interrupt, 1: X high event has occurred)
#define INT1_SRC_YL		(1U<<2)		// Y low. Default value: 0 (0: no interrupt, 1: Y low event has occurred)
#define INT1_SRC_YH		(1U<<3)		// Y high. Default value: 0 (0: no interrupt, 1: Y high event has occurred)
#define INT1_SRC_ZL		(1U<<4)		// Z low. Default value: 0 (0: no interrupt, 1: Z low event has occurred)
#define INT1_SRC_ZH		(1U<<5)		// Z high. Default value: 0 (0: no interrupt, 1: Z high event has occurred)
#define INT1_SRC_IA		(1U<<6)		// Interrupt active. Default value: 0 (0: no interrupt has been generated, 1: one or more interrupts have been generated)







////////////////////			INT1_THS_A  description			/////////////////////////////////
/*
 * 		THS[6:0] ->>>>>	Interrupt 1 threshold. Default value: 000 0000
 * */

#define INT1_THS_THS0	(1U<<0)		// Default value: 0
#define INT1_THS_THS1	(1U<<1)		// Default value: 0
#define INT1_THS_THS2	(1U<<2)		// Default value: 0
#define INT1_THS_THS3	(1U<<3)		// Default value: 0
#define INT1_THS_THS4	(1U<<4)		// Default value: 0
#define INT1_THS_THS5	(1U<<5)		// Default value: 0
#define INT1_THS_THS6	(1U<<6)		// Default value: 0






////////////////////			INT1_DURATION_A  description			//////////////////////////
/*
 * 		D[6:0] -> Duration value. Default value: 000 0000
 *
 * 		D6 - D0 bits set the minimum duration of the Interrupt 1 event to be recognized.
 * 		Duration steps and maximum values depend on the ODR chosen.
 * */

#define INT1_DURATION_D0	(1U<<0)		// Default value: 0
#define INT1_DURATION_D1	(1U<<1)		// Default value: 0
#define INT1_DURATION_D2 	(1U<<2)		// Default value: 0
#define INT1_DURATION_D3	(1U<<3)		// Default value: 0
#define INT1_DURATION_D4	(1U<<4)		// Default value: 0
#define INT1_DURATION_D5	(1U<<5)		// Default value: 0
#define INT1_DURATION_D6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////







////////////////////			INT2_CFG_A  description			/////////////////////////////////////
/*
 * 	    	AND/OR combination of interrupt events. Default value: 0
 * 		AOI		6D		Interrupt mode
 * 		0		0		OR combination of interrupt events
 * 		0		1		6-direction movement recognition
 * 		1		0		AND combination of interrupt events
 * 		1		1		6-direction position recognition
 *
 *
 * 		Difference between AOI-6D = ‘01’ and AOI-6D = ‘11’.
 * 		AOI-6D = ‘01’ is movement recognition. An interrupt is generated when the orientation
 * 		moves from an unknown zone to a known zone. The interrupt signal remains for a duration ODR.
 * 		AOI-6D = ‘11’ is direction recognition. An interrupt is generated when the orientation is
 * 		inside a known zone. The interrupt signal remains until the orientation is inside the zone.
 */

#define INT2_CFG_XLIE	(1U<<0)		// Enable interrupt generation on X low event. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value lower than preset threshold)
#define INT2_CFG_XHIE	(1U<<1)		// Enable interrupt generation on X high event. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define INT2_CFG_YLIE 	(1U<<2)		// Enable interrupt generation on Y low event. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value lower than preset threshold)
#define INT2_CFG_YHIE	(1U<<3)		// Enable interrupt generation on Y high event. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define INT2_CFG_ZLIE	(1U<<4)		// Enable interrupt generation on Z low event. Default value: 0 (0: disable interrupt request,  1: enable interrupt request on measured accel. value lower than preset threshold)
#define INT2_CFG_ZHIE	(1U<<5)		// Enable interrupt generation on Z high event. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define INT2_CFG_6D 	(1U<<6)		// 6-direction detection function enabled. Default value: 0
#define INT2_CFG_AOI 	(1U<<7)		// AND/OR combination of interrupt events. Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////





////////////////////			INT2_SRC_A  description			////////////////////////////////////////
/*
 * 	Interrupt 2 source register. Read-only register.
 * 	Reading at this address clears the INT2_SRC IA bit (and the interrupt signal on the INT2
 * 	pin) and allows the refresh of data in the INT2_SRC register if the latched option was
 * 	chosen.
 */

#define INT2_SRC_XL		(1U<<0)		// X Low. Default value: 0 (0: no interrupt, 1: X low event has occurred)
#define INT2_SRC_XH		(1U<<1)		// X high. Default value: 0 (0: no interrupt, 1: X high event has occurred)
#define INT2_SRC_YL 	(1U<<2)		// Y low. Default value: 0 (0: no interrupt, 1: Y low event has occurred)
#define INT2_SRC_YH		(1U<<3)		// Y high. Default value: 0 (0: no interrupt, 1: Y high event has occurred)
#define INT2_SRC_ZL		(1U<<4)		// Z low. Default value: 0 (0: no interrupt, 1: Z low event has occurred)
#define INT2_SRC_ZH		(1U<<5)		// Z high. Default value: 0 (0: no interrupt, 1: Z high event has occurred)
#define INT2_SRC_IA		(1U<<6)		// Interrupt active. Default value: 0 (0: no interrupt has been generated, 1: one or more interrupts have been generated)
////////////////////////////////////////////////////////////////////////////////////////////////////////








////////////////////			INT1_THS_A  description			///////////////////////////////////////////
/*
 * 		THS[6:0] ->>>>>	Interrupt 2 threshold. Default value: 000 0000
 * */

#define INT2_THS_THS0	(1U<<0)		// Default value: 0
#define INT2_THS_THS1	(1U<<1)		// Default value: 0
#define INT2_THS_THS2	(1U<<2)		// Default value: 0
#define INT2_THS_THS3	(1U<<3)		// Default value: 0
#define INT2_THS_THS4	(1U<<4)		// Default value: 0
#define INT2_THS_THS5	(1U<<5)		// Default value: 0
#define INT2_THS_THS6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////			INT2_DURATION_A  description			//////////////////////////
/*
 * 		D[6:0] -> Duration value. Default value: 000 0000
 *
 * 		D6 - D0 bits set the minimum duration of the Interrupt 2 event to be recognized.
 * 		Duration steps and maximum values depend on the ODR chosen.
 * */

#define INT2_DURATION_D0	(1U<<0)		// Default value: 0
#define INT2_DURATION_D1	(1U<<1)		// Default value: 0
#define INT2_DURATION_D2 	(1U<<2)		// Default value: 0
#define INT2_DURATION_D3	(1U<<3)		// Default value: 0
#define INT2_DURATION_D4	(1U<<4)		// Default value: 0
#define INT2_DURATION_D5	(1U<<5)		// Default value: 0
#define INT2_DURATION_D6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////			CLICK_CFG_A  description			/////////////////////////////////////
/*
 *
 */

#define CLICK_CFG_XS	(1U<<0)		// Enable interrupt single-click on X-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define CLICK_CFG_XD	(1U<<1)		// Enable interrupt double-click on X-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define CLICK_CFG_YS 	(1U<<2)		// Enable interrupt single-click on Y-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define CLICK_CFG_YD	(1U<<3)		// Enable interrupt double-click on Y-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define CLICK_CFG_ZS	(1U<<4)		// Enable interrupt single-click on Z-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)
#define CLICK_CFG_ZD	(1U<<5)		// Enable interrupt double-click on Z-axis. Default value: 0 (0: disable interrupt request, 1: enable interrupt request on measured accel. value higher than preset threshold)

////////////////////////////////////////////////////////////////////////////////////////////////////////







////////////////////			CLICK_SRC_A  description			/////////////////////////////////////
/*
 *
 * */

#define CLICK_SRC_X			(1U<<0)		// X-click detection. Default value: 0 (0: no interrupt, 1: X high event has occurred)
#define CLICK_SRC_Y			(1U<<1)		// Y-click detection. Default value: 0 (0: no interrupt, 1: Y high event has occurred)
#define CLICK_SRC_Z	 		(1U<<2)		// Z-click detection. Default value: 0 (0: no interrupt, 1: Z high event has occurred)
#define CLICK_SRC_SIGN		(1U<<3)		// Click sign. 0: positive detection, 1: negative detection
#define CLICK_SRC_SCLICK	(1U<<4)		// Single-click enable. Default value: 0 (0: Single-click detection disable, 1: single-click detection enable)
#define CLICK_SRC_DCLICK	(1U<<5)		// Double-click enable. Default value: 0 (0: double-click detection disable, 1: double-click detection enable)
#define CLICK_SRC_IA		(1U<<6)		// Interrupt active. Default value: 0 (0: no interrupt has been generated, 1: one or more interrupts have been generated)
////////////////////////////////////////////////////////////////////////////////////////////////////////






////////////////////			CLICK_THS_A  description			///////////////////////////////////////////
/*
 * 		THS[6:0] ->>>>>	Interrupt 2 threshold. Default value: 000 0000
 *
 * 		1 LSB = full-scale / 128. Ths6 through Ths0 define the threshold which is used by the
 * 		system to start the click-detection procedure. The threshold value is expressed over 7 bits
 * 		as an unsigned number.
 *
 * */

#define CLICK_THS_THS0	(1U<<0)		// Default value: 0
#define CLICK_THS_THS1	(1U<<1)		// Default value: 0
#define CLICK_THS_THS2	(1U<<2)		// Default value: 0
#define CLICK_THS_THS3	(1U<<3)		// Default value: 0
#define CLICK_THS_THS4	(1U<<4)		// Default value: 0
#define CLICK_THS_THS5	(1U<<5)		// Default value: 0
#define CLICK_THS_THS6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////








////////////////////			TIME_LIMIT_A  description			///////////////////////////////////////////
/*
 * 		TLI[6:0]->>>>>	Click time limit. Default value: 000 0000
 *
 * 		1 LSB = 1/ODR. TLI6 through TLI0 define the maximum time interval that can elapse
 * 		between the start of the click-detection procedure (the acceleration on the selected channel
 * 		exceeds the programmed threshold) and when the acceleration falls below the threshold.
 *
 * */

#define TIME_LIMIT_TLI0	(1U<<0)		// Default value: 0
#define TIME_LIMIT_TLI1	(1U<<1)		// Default value: 0
#define TIME_LIMIT_TLI2	(1U<<2)		// Default value: 0
#define TIME_LIMIT_TLI3	(1U<<3)		// Default value: 0
#define TIME_LIMIT_TLI4	(1U<<4)		// Default value: 0
#define TIME_LIMIT_TLI5	(1U<<5)		// Default value: 0
#define TIME_LIMIT_TLI6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////







////////////////////			TIME_LATENCY_A  description			///////////////////////////////////////////
/*
 * 		TLA[6:0]->>>>>	Double-click time latency. Default value: 0000 0000
 *
 * 		1 LSB = 1/ODR. TLA7 through TLA0 define the time interval that starts after the first click
 * 		detection where the click-detection procedure is disabled, in cases where the device is
 * 		configured for double-click detection.
 * */

#define TIME_LATENCY_TLA0	(1U<<0)		// Default value: 0
#define TIME_LATENCY_TLA1	(1U<<1)		// Default value: 0
#define TIME_LATENCY_TLA2	(1U<<2)		// Default value: 0
#define TIME_LATENCY_TLA3	(1U<<3)		// Default value: 0
#define TIME_LATENCY_TLA4	(1U<<4)		// Default value: 0
#define TIME_LATENCY_TLA5	(1U<<5)		// Default value: 0
#define TIME_LATENCY_TLA6	(1U<<6)		// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////








////////////////////			TIME_WINDOW_A  description			///////////////////////////////////////////
/*
 * 		T2[7:0]->>>>>	Double-click time window
 *
 * 		1 LSB = 1/ODR. TW7 through TW0 define the maximum interval of time that can elaps
 * 		after the end of the latency interval in which the click detection procedure can start, in cases
 * 		where the device is configured for double-click detection.
 * */

#define TIME_WINDOW_TW0	(1U<<0)		// Default value: 0
#define TIME_WINDOW_TW1	(1U<<1)		// Default value: 0
#define TIME_WINDOW_TW2	(1U<<2)		// Default value: 0
#define TIME_WINDOW_TW3	(1U<<3)		// Default value: 0
#define TIME_WINDOW_TW4	(1U<<4)		// Default value: 0
#define TIME_WINDOW_TW5	(1U<<5)		// Default value: 0
#define TIME_WINDOW_TW6	(1U<<6)		// Default value: 0
#define TIME_WINDOW_TW7	(1U<<7) 	// Default value: 0
////////////////////////////////////////////////////////////////////////////////////////////////////////////



//
//
//
//
//
//void lsm303dlhc_init_la(I2C_HandleTypeDef *i2c);
//
//void lsm303dlhc_read_la(I2C_HandleTypeDef *i2c, float *bufX, float *bufY, float *bufZ);
//
//










/*
 *
 *
 *
 *
 *
 * 											PART MAGNETIC SENSOR
 * 											TODO: DEFINE MAGNETIC SENSOR REGISTER
 *
 *
 *
 *
 * */









//////////////////// Magnetic field sensing register description ///////////////////

#define CRA_REG_M		0x00		// Default 0001000
#define CRB_REG_M		0x01		// Default 0010000
#define MR_REG_M		0x02		// Default 00000011
#define OUT_X_H_M 		0x03		// Default output
#define OUT_X_L_M		0x04		// Default output
#define OUT_Z_H_M		0x05		// Default output
#define OUT_Z_L_M		0x06		// Default output
#define OUT_Y_H_M		0x07		// Default output
#define OUT_Y_L_M		0x08		// Default output
#define SR_REG_M		0x09		// Default 00000000
#define IRA_REG_M 		0x0A		// Default 01001000
#define IRB_REG_M		0x0B		// Default 00110100
#define IRC_REG_M		0x0C		// Default 00110011
#define Reserved3		0x0D		// Default reserved
#define TEMP_OUT_H_M	0x31		// Default output
#define TEMP_OUT_L_M	0x32		// Default output
















