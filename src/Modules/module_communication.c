#include "module_communication.h"

#INT_RDA
void communication_getPacket()
{	
	com_flg_active = true;
	
	if(packet.str.start[0] != c_com_first)
		com_packet_position = 0;
	else if (packet.str.start[1] != c_com_second)
		com_packet_position = 1;
	
	packet.chunk[com_packet_position++] = hal_com1_getc();

	if(com_packet_position>=c_com_packet_size){
		com_flg_packet_ready = true;
		com_packet_position=0;
	}
}

void communication_doCommand(char command)
{
	/*switch(command){
		case _comcmd_test: communication_test(); break;
	}*/
}

void communication_work()
{
}

