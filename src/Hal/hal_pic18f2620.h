#ifndef _HAL_H
#define _HAL_H

/**
 * Abstract: Hardware abstraction layer
 * Author: Diego Arnaudin
 */

/* ports definitions */

#define hal_io_PA_0 PIN_A0
#define hal_io_PA_1 PIN_A1
#define hal_io_PA_2 PIN_A2
#define hal_io_PA_3 PIN_A3
#define hal_io_PA_4 PIN_A4
#define hal_io_PA_5 PIN_A5
#define hal_io_PA_6 PIN_A6
#define hal_io_PA_7 PIN_A7

#define hal_io_PB_0 PIN_B0
#define hal_io_PB_1 PIN_B1
#define hal_io_PB_2 PIN_B2
#define hal_io_PB_3 PIN_B3
#define hal_io_PB_4 PIN_B4
#define hal_io_PB_5 PIN_B5
#define hal_io_PB_6 PIN_B6
#define hal_io_PB_7 PIN_B7


#define hal_io_PC_0 PIN_C0
#define hal_io_PC_1 PIN_C1
#define hal_io_PC_2 PIN_C2
#define hal_io_PC_3 PIN_C3
#define hal_io_PC_4 PIN_C4
#define hal_io_PC_5 PIN_C5
#define hal_io_PC_6 PIN_C6
#define hal_io_PC_7 PIN_C7

/* application specific settings */


/* device specific settings */

#define hal_debug_tx hal_io_PC_1
#define hal_debug_rx hal_io_PC_0

#define hal_com1_tx hal_io_PC_6
#define hal_com1_rx hal_io_PC_7


#include <18F2620.h>
   #fuses   NOWDT
   #fuses   INTRC_IO
   #fuses   PUT
   #fuses   PROTECT
   #fuses   NODEBUG
   #fuses   BROWNOUT
   #fuses   NOLVP
   #fuses   NOCPD
   #fuses   NOWRT
   #use delay(clock=32000000)
   
#use rs232(baud=19200,parity=N,xmit=hal_debug_tx,rcv=hal_debug_rx,bits=8,stream=hal_stream_debug)

#use rs232(baud=9600,parity=N,xmit=hal_com1_tx, rcv=hal_com1_rx,bits=8,stream=hal_stream_com1)

/* compiler functions redefines */

#define hal_input(x) input(x)
#define hal_delay_ms(x) delay_ms(x)
#define hal_reset() reset_cpu()
#define hal_output_pin(p, v) output_bit(p, v)

#define hal_debug_printf(f_, ...) fprintf(hal_stream_debug,(f_), __VA_ARGS__)
#define hal_debug_putc(x) fputc(x,hal_stream_debug)
#define hal_debug_getc() fgetc(hal_stream_debug)

#define hal_com1_printf(f_, ...) fprintf(hal_stream_com1,(f_), __VA_ARGS__)
#define hal_com1_putc(x) fputc(x,hal_stream_com1)
#define hal_com1_getc() fgetc(hal_stream_com1)

/* data types */

#define true 1
#define false 0

#define hal_bool int1
#define hal_int8 int8
#define hal_int16 int16
#define hal_int32 int32
#define hal_float float
#define hal_address int16


/* handy things */

#define ever ;;

/* prototypes */

void hal_initialize();


/* implementations */

/* comment or uncomment to toggle debug messages */

#ifndef debug
	#define hal_debug_printf(f_, ...)
#endif


void hal_initialize()
{
	hal_debug_printf("HAL->Initialize()\r\n");
	hal_debug_printf("HAL->StartingHardware.\r\n");
	delay_ms(500);
	/* adc settings */
	//hal_debug_printf("HAL: starting adc.\r\n");
	
	/* setup interruptions */
	hal_debug_printf("HAL->SettingInterruptions.\r\n");
	enable_interrupts(GLOBAL);
	enable_interrupts(INT_RDA);
	//enable_interrupts(INT_EXT);
	
	/* other settings */
	set_tris_b(0x00);
	/* end of initialization */
	hal_debug_printf("HAL->StartComplete.\r\n");
}

#endif /* _HAL_H */