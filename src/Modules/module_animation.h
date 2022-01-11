#ifndef _module_animation_h
#define _module_animation_h

/* Globals */
hal_int8 anim = 0;
/* Constants */
enum anims {_rotate_right, _rotate_left};
/* Commands */
#define _animcmd_set_rotate_right 'r'
#define _animcmd_set_rotate_left 'l'

void animation_work();
void animation_doCommand(hal_int8);
void animation_doCommandILD(hal_int8, hal_int16, void*);
void animation_doCommandD(hal_int8, void*);

#endif // _module_animation_h

