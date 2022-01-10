/* Application */

void application_init()
{
	/* load memory */
	/* load selected */
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
				mod_memory.doCommandD(_memcmd_write_page, packet.str.data);				
				com_flg_packet_ready = false;
				if(mem_page>1){
					com_flg_active = false;
					mod_memory.doCommand(_memcmd_reset_page);
					application_init();
				}
			}
		}		
		// else
		if(!com_flg_active){	
			/* check buttons */	
			mod_buttons.work();
			/* screen work */
			/* animation work */
		}
	}
}