#include "module_led8x8.h"

void led8x8_refresh(hal_int8* buffer)
{
	for(int row=0; row<2; row++){
		hal_int8 multiplier = 0x80;
		for(int col=0; col<8; col++){
			_led8x8_sendData(buffer[row] & multiplier);
			_led8x8_sendClk();
			multiplier >>= 1;
		}
	}
	_led8x8_sendStb();
}

void led8x8_doCommand(hal_int8 command)
{
	switch(command){
		case 0: break;
	}
}

void led8x8_doCommandD(hal_int8 command, void* param)
{	
	hal_int8* p = param;
	switch(command){
		case _led8x8cmd_refresh: led8x8_refresh(p); break;
	}
}

void led8x8_doCommandILD(hal_int8 command, hal_int16 param1, hal_int16 param2, void* param3)
{
	switch(command){
		case 0: break;
	}
}

void led8x8_work()
{
}
