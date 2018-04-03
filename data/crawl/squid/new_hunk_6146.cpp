	cachemgrInit();
	statInit();
	storeInit();
	mainSetCwd();
	/* after this point we want to see the mallinfo() output */
	do_mallinfo = 1;
	mimeInit(Config.mimeTablePathname);
