    openlog("msnt_auth", LOG_PID, LOG_USER);
    setbuf(stdout, NULL);

    for (int j = 1; j < argc; ++j) {
    	std::string arg = argv[j];
    	size_t pos=arg.find('/');
    	if (arg.find('/',pos+1)) {
    		std::cerr << "Error: can't understand domain controller specification '"
    				<< arg << '"' << std::endl;
    		exit(1);
    	}
    	domaincontroller dc;
    	dc.domain = arg.substr(0,pos);
    	dc.server = arg.substr(pos+1);
    	if (dc.domain.length() == 0 || dc.server.length() == 0) {
    		std::cerr << "Error: invalid domain specification in '" << arg <<
    				"'" << std::endl;
    		exit(1);
    	}
    	domaincontrollers.push_back(dc);
    }

    while (1) {
        int n;
        /* Read whole line from standard input. Terminate on break. */
