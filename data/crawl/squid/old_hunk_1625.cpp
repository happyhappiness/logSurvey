            return 1;
        }

        WIN32_Service_name = xstrdup(c+1);
        DispatchTable[0].lpServiceName=WIN32_Service_name;
        strcat(REGKEY, WIN32_Service_name);
        keys[4] = WIN32_Service_name;

        if (!StartServiceCtrlDispatcher(DispatchTable)) {
            fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
