#ifndef _module_screen_h
#define _module_screen_h

#include "./module_led8x8.h"
#include "./module_led8x8.c"

/* Globals */
Module_Interface mod_led;

/* Constants */
/* Commands */
#define _screencmd_load8x8 '8'

void screen_work();
void screen_doCommand(hal_int8);
void screen_doCommandILD(hal_int8, hal_int16, void*);
void screen_doCommandD(hal_int8, void*);

#endif // _module_screen_h

