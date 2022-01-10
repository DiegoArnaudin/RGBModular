#define debug

#include "./src/Hal/hal_pic18f2620.h"
#include "./src/Modules/module_interface.h"
#include "./src/Modules/module_memory.h"
#include "./src/Modules/module_memory.c"
#include "./src/Modules/module_communication.h"
#include "./src/Modules/module_communication.c"
#include "./src/Modules/module_buttons.h"
#include "./src/Modules/module_buttons.c"
#include "./src/application.c"

void loadMem(Module_Interface *module)
{
    (*module).doCommandILD = memory_doCommandILD;
    (*module).doCommand = memory_doCommand;
    (*module).doCommandD = memory_doCommandD;
}

void loadCom(Module_Interface *module)
{
    (*module).doCommand = communication_doCommand;
    (*module).work = communication_work;
}

void loadButtons(Module_Interface *module)
{
    (*module).doCommand = buttons_doCommand;
    (*module).work = buttons_work;
}

void main() 
{
	hal_initialize();
	
	loadMem(&mod_memory);
	loadCom(&mod_communication);
	loadButtons(&mod_buttons);
	
	application_run();
	
	
}