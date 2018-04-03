            return 1;
        }

        service_name = xstrdup(c+1);
        DispatchTable[0].lpServiceName=service_name;
        strcat(REGKEY, service_name);
        keys[4] = service_name;

        if (!StartServiceCtrlDispatcher(DispatchTable)) {
            fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
