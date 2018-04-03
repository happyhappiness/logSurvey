	    debug(14, 3, "ipcache_init: 'dns_server' %d started\n", i);
	}
    }
    ipcache_high = (long) (((float) MAX_IP *
	    (float) IP_HIGH_WATER) / (float) 100);
    ipcache_low = (long) (((float) MAX_IP *
	    (float) IP_LOW_WATER) / (float) 100);


    ipcache_initialized = 1;
}

