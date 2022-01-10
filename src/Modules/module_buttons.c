#include "module_buttons.h"

void buttons_printState()
{
	hal_debug_printf("buttons_printState(): _buttons_b1[%c] _buttons_b2[%c] \r\n",
		(buttons_state&_buttons_b1)?'x':' ',
		(buttons_state&_buttons_b2)?'x':' '
		);
}
void buttons_doCommand(char command)
{
	switch(command){
		case _btncmd_print_state: buttons_printState(); break;
	}
}

void buttons_work()
{
	buttons_state = (hal_input(hal_io_PB_0) * _buttons_b1) |
			(hal_input(hal_io_PB_1) * _buttons_b2);
			
	if(buttons_state)
		buttons_printState();
}

