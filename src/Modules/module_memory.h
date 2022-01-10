#ifndef _module_memory_h
#define _module_memory_h

/* Globals */
hal_int16 mem_page = 0;
/* Constants */
#define c_mem_page_size 16

/* Commands */
#define _memcmd_write 'w'
#define _memcmd_read 'r'
#define _memcmd_dump 'd'
#define _memcmd_write_page 'p'
#define _memcmd_reset_page 'r'

void memory_work();
void memory_doCommand(hal_int8);
void memory_doCommandILD(hal_int8, hal_int16, void*);
void memory_doCommandD(hal_int8, void*);

#endif // _module_memory_h

