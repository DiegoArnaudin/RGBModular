#define debug

#include "./src/Hal/hal_pic18f2620.h"
#include "./src/Modules/module_interface.h"
#include "./src/Modules/module_memory.h"
#include "./src/Modules/module_memory.c"
#include "./src/Modules/module_communication.h"
#include "./src/Modules/module_communication.c"
#include "./src/Modules/module_buttons.h"
#include "./src/Modules/module_buttons.c"
#include "./src/Modules/module_screen.h"
#include "./src/Modules/module_screen.c"
#include "./src/Modules/module_animation.h"
#include "./src/Modules/module_animation.c"

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

void loadScreen(Module_Interface *module)
{
    (*module).doCommand = screen_doCommand;
    (*module).work = screen_work;
}

void loadAnimation(Module_Interface *module)
{
    (*module).work = animation_work;
    (*module).doCommand = animation_doCommand;
}

void main() 
{
	hal_initialize();
	
	loadMem(&mod_memory);
	loadCom(&mod_communication);
	loadButtons(&mod_buttons);
	loadScreen(&mod_screen);
	loadAnimation(&mod_animation);
	
	application_run();
}