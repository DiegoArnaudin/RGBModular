#ifndef _module_led8x8_h
#define _module_led8x8_h

/* Globals */
/* Constants */
#define _led8x8_data hal_io_PB_2
#define _led8x8_clk hal_io_PB_3
#define _led8x8_stb hal_io_PB_4

#define _led8x8_sendData(x) hal_output_pin(_led8x8_data, x)
#define _led8x8_sendClk() hal_output_pin(_led8x8_clk, 1); hal_output_pin(_led8x8_clk, 0)
#define _led8x8_sendStb() hal_output_pin(_led8x8_stb, 1); hal_output_pin(_led8x8_stb, 0)
/* Commands */
#define _led8x8cmd_refresh 'r'

void led8x8_work();
void led8x8_doCommand(hal_int8);
void led8x8_doCommandILD(hal_int8, hal_int16, void*);
void led8x8_doCommandD(hal_int8, void*);

#endif // _module_led8x8_h

