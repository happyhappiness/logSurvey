#endif
#endif

    while ((c = getopt(argc, argv, "Ddhs:v")) != -1) {
	switch (c) {
	case 'D':
#ifdef RES_DEFNAMES
	    _res.options |= RES_DEFNAMES;
