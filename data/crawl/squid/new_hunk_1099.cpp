    openlog("msnt_auth", LOG_PID, LOG_USER);
    setbuf(stdout, NULL);

    for (int j = 1; j < argc; ++j) {
        std::string arg = argv[j];
        size_t pos=arg.find('/');
        if (arg.find('/',pos+1) != std::string::npos) {
            std::cerr << "Error: can't understand domain controller specification '"
                      << arg << "'. Ignoring" << std::endl;
        }
        domaincontroller dc;
        dc.domain = arg.substr(0,pos);
        dc.server = arg.substr(pos+1);
        if (dc.domain.length() == 0 || dc.server.length() == 0) {
            std::cerr << "Error: invalid domain specification in '" << arg <<
                      "'. Ignoring." << std::endl;
            exit(1);
        }
        domaincontrollers.push_back(dc);
    }
    if (domaincontrollers.empty()) {
        display_usage_instructions();
        std::cerr << "Error: no domain controllers specified" << std::endl;
        exit(1);
    }

    while (1) {
        int n;
