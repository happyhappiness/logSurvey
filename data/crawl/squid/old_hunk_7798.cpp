	stat_init(&CacheInfo, getAccessLogFile());
	storeInit();
	stmemInit();
	writePidFile();

	/* after this point we want to see the mallinfo() output */
	do_mallinfo = 1;
    }
