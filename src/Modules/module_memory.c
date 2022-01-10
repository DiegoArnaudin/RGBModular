#include "module_memory.h"

// memoria dummy
char mem_dummy[32] = "";

void memory_dump()
{
	hal_debug_printf("memory_dump():[");
	for(int i=0; i<32; i++)
		hal_debug_putc(mem_dummy[i]);
	hal_debug_printf("]\r\n");
}

void memory_doCommand(hal_int8 command)
{
	switch(command){
		case _memcmd_dump: memory_dump(); break;
		case _memcmd_reset_page: mem_page = 0; break;
	}
}

void memory_doWrite(hal_int16 address, hal_int16 length, hal_int8* data)
{
	hal_debug_printf("Writting (%lu, %lu)...\r\n", address, length);
	for(int i=0; i<length; i++)
		mem_dummy[address+i] = data[i];
}
void memory_doRead(hal_int16 address, hal_int16 length, hal_int8* data)
{
	hal_debug_printf("Reading (%lu, %lu)...\r\n", address, length);
	for(int i=0; i<length; i++)
		data[i] = mem_dummy[address+i];
}

void memory_doCommandD(hal_int8 command, void* param)
{	
	hal_debug_printf("memory_doCommandD\r\n");
	hal_int8* p = param;
	switch(command){
		case _memcmd_write_page: memory_doWrite(mem_page*c_mem_page_size, c_mem_page_size, p); mem_page++; break;
	}
}

void memory_doCommandILD(hal_int8 command, hal_int16 param1, hal_int16 param2, void* param3)
{
	hal_int8* p = param3;
	switch(command){
		case _memcmd_write: memory_doWrite(param1, param2, p); break;
		case _memcmd_read: memory_doRead(param1, param2, p); break;
		case _memcmd_write_page: memory_doWrite(param1*c_mem_page_size, param2, p); mem_page++; break;
	}
}
