/* Application */

hal_int16 timer = 1000;

void application_init()
{
	/* load memory */
	/* load selected */
	
	/* initialize led modules */
	mod_screen.doCommand(_screencmd_load8x8);
}

void application_run()
{
	/* init */
	application_init();
	
	/* main loop */
	while(true){		
		/* check com flag */
		if(com_flg_active){
			if(com_flg_packet_ready){
				if(packet.str.command == _cmd_write_mem){
					mod_memory.doCommandD(_memcmd_write_page, packet.str.data);				
					com_flg_packet_ready = false;
					if(mem_page>1){
						com_flg_active = false;
						mod_memory.doCommand(_memcmd_reset_page);
						application_init();
					}
				}
				else
				if(packet.str.command == _cmd_rotate_left){
					com_flg_packet_ready = false;
					com_flg_active = false;
					mod_animation.doCommand(_animcmd_set_rotate_left);
				}
				else
				if(packet.str.command == _cmd_rotate_right){
					com_flg_packet_ready = false;
					com_flg_active = false;
					mod_animation.doCommand(_animcmd_set_rotate_right);
				}
			}
			mod_communication.work();
		}		
		// else
		if(!com_flg_active){	
			/* check buttons */	
			mod_buttons.work();
			/* screen work */
			mod_screen.work();
			/* animation work */
			if(!--timer){
				mod_animation.work();
				timer = 1000;
			}
		}
	}
}