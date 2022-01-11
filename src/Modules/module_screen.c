#include "module_screen.h"

void load8x8()
{
	mod_led.doCommandD = led8x8_doCommandD;
	hal_debug_printf("led8x8 selected.\r\n");
}

void screen_doCommand(hal_int8 command)
{
	switch(command){
		case _screencmd_load8x8: load8x8(); break;
	}
}

void screen_doCommandD(hal_int8 command, void* param)
{	
	switch(command){
		case 0: break;
	}
}

void screen_doCommandILD(hal_int8 command, hal_int16 param1, hal_int16 param2, void* param3)
{
	switch(command){
		case 0: break;
	}
}

/* Posibly this need to be an interrupt */
void screen_work()
{
	mod_led.doCommandD(_led8x8cmd_refresh, leds);
}
