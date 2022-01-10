/* Interface */
#ifndef _module_interface_h
#define _module_interface_h

typedef void (*Work)(void);
typedef void (*DoCommand)(hal_int8);
typedef void (*DoCommandD)(hal_int8, void*);
typedef void (*DoCommandID)(hal_int8, hal_int16, void*);
typedef void (*DoCommandILD)(hal_int8, hal_int16, hal_int16, void*);

typedef struct Module_Interface{
    Work work;
    DoCommand doCommand;
    DoCommandD doCommandD;
    DoCommandID doCommandID;
    DoCommandILD doCommandILD;
}Module_Interface;

Module_Interface mod_memory, mod_communication, mod_buttons;

#endif /* _module_interface_h */
