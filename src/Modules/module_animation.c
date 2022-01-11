#include "module_animation.h"

void animation_rotateLeft()
{
	rotate_left(leds, 2);
}

void animation_rotateRight()
{
	rotate_right(leds, 2);
}


typedef void (*FuncAnim)(void);
FuncAnim doFuncAnim = animation_rotateLeft;

void animation_doCommand(hal_int8 command)
{
	switch(command){
		case _animcmd_set_rotate_right: anim = _rotate_right; break;
		case _animcmd_set_rotate_left: anim = _rotate_left; break;
	}
}

void animation_doCommandD(hal_int8 command, void* param)
{	
	switch(command){
		case 0: break;
	}
}

void animation_doCommandILD(hal_int8 command, hal_int16 param1, hal_int16 param2, void* param3)
{
	switch(command){
		case 0: break;
	}
}

void animation_work()
{
	/*animate*/
	switch(anim){
		case _rotate_right: animation_rotateRight(); break;
		case _rotate_left: animation_rotateLeft(); break;
	}
}
