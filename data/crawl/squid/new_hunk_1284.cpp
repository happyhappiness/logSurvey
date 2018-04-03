            return 1;
        }

        service_name = SBuf(c+1);
        const char *service = service_name.c_str();
        DispatchTable[0].lpServiceName=service;
        strcat(REGKEY, service);
        keys[4] = service;

        if (!StartServiceCtrlDispatcher(DispatchTable)) {
            fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
