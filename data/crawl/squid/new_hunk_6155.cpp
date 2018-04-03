		(int) total_bytes_read / 1024 / 1024,
		(int) total_bytes_read / 1024 / dt);
	    reqpersec = 0;
	    /*
	     * if (dt > process_lifetime)
	     *     exit(0);
	     */
	}
    }
    printf("Exiting normally\n");
    return 0;
}
