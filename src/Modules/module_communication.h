#ifndef _module_communication_h
#define _module_communication_h

/* Constants */
#define c_com_packet_size 20

#define c_com_first 0x61
#define c_com_second 0x62
#define c_com_command_position 2

enum commands { _cmd_write_mem='0', _cmd_rotate_left, _cmd_rotate_right};

/* Globals */
union {
	hal_int8 chunk[c_com_packet_size];
	struct{
		hal_int8 start[2];
		hal_int8 command;
		hal_int8 data[16];
		hal_int8 chk;
	} str;	
} packet;

hal_bool com_flg_packet_ready = false;
hal_bool com_flg_active = false;
hal_int8 com_packet_position = 0;

/* Commands */
//#define _comcmd_test 't'

/* Prototypes */
void communication_doCommand(char);
void communication_work();

#endif // _module_communication_h

