#ifndef _module_buttons_h
#define _module_buttons_h

/* Globals */
hal_int8 buttons_state = 0;

/* Constants */
#define _buttons_b1 0x01
#define _buttons_b2 0x02

/* Commands */
#define _btncmd_print_state 's'

/* Prototypes */

void buttons_work();
void buttons_doCommand(hal_int8);

#endif // _module_buttons_h

