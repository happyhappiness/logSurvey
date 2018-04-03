    if (atexit(WIN32_Exit) != 0)
        return 1;

#ifdef USE_WIN32_SERVICE

    if (WIN32_run_mode == _WIN_SQUID_RUN_MODE_SERVICE)
    {
        char path[512];
        HKEY hndKey;

        if (signal(SIGABRT, WIN32_Abort) == SIG_ERR)
            return 1;

        /* Register the service Handler function */
        svcHandle =
            RegisterServiceCtrlHandler(WIN32_Service_name,
                                       WIN32_svcHandler);

        if (svcHandle == 0)
            return 1;

        /* Set Process work dir to directory cointaining squid.exe */
        GetModuleFileName(NULL, path, 512);

        WIN32_module_name=xstrdup(path);

        path[strlen(path) - 10] = '\0';

        if (SetCurrentDirectory(path) == 0)
            return 1;

        safe_free(ConfigFile);

        /* get config file from Windows Registry */
        if (RegOpenKey(HKEY_LOCAL_MACHINE, REGKEY, &hndKey) == ERROR_SUCCESS) {
            DWORD Type = 0;
            DWORD Size = 0;
            LONG Result;
            Result =
                RegQueryValueEx(hndKey, CONFIGFILE, NULL, &Type, NULL, &Size);

            if (Result == ERROR_SUCCESS && Size) {
                ConfigFile = static_cast<char *>(xmalloc(Size));
                RegQueryValueEx(hndKey, CONFIGFILE, NULL, &Type, (unsigned char *)ConfigFile,
                                &Size);
            } else
                ConfigFile = xstrdup(DefaultConfigFile);

            Size = 0;

            Type = 0;

            Result =
                RegQueryValueEx(hndKey, COMMANDLINE, NULL, &Type, NULL, &Size);

            if (Result == ERROR_SUCCESS && Size) {
                WIN32_Service_Command_Line = static_cast<char *>(xmalloc(Size));
                RegQueryValueEx(hndKey, COMMANDLINE, NULL, &Type, (unsigned char *)WIN32_Service_Command_Line,
                                &Size);
            } else
                WIN32_Service_Command_Line = xstrdup("");

            RegCloseKey(hndKey);
        } else {
            ConfigFile = xstrdup(DefaultConfigFile);
            WIN32_Service_Command_Line = xstrdup("");
        }

        WIN32_build_argv(WIN32_Service_Command_Line);
        *argc = WIN32_argc;
        *argv = WIN32_argv;
        /* Set Service Status to SERVICE_START_PENDING */
        svcStatus.dwServiceType = SERVICE_WIN32_OWN_PROCESS;
        svcStatus.dwCurrentState = SERVICE_START_PENDING;
        svcStatus.dwControlsAccepted =
            SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN;
        svcStatus.dwWin32ExitCode = 0;
        svcStatus.dwServiceSpecificExitCode = 0;
        svcStatus.dwCheckPoint = 0;
        svcStatus.dwWaitHint = 10000;
        SetServiceStatus(svcHandle, &svcStatus);

    }

#endif

    return 0;
}

#ifdef USE_WIN32_SERVICE
void
WIN32_svcstatusupdate(DWORD svcstate, DWORD WaitHint)
{
    if (WIN32_run_mode == _WIN_SQUID_RUN_MODE_SERVICE) {
        svcStatus.dwCheckPoint++;
        svcStatus.dwWaitHint = WaitHint;
        svcStatus.dwCurrentState = svcstate;
        SetServiceStatus(svcHandle, &svcStatus);
    }
}

VOID WINAPI
WIN32_svcHandler(DWORD Opcode)
{
    DWORD status;

    switch (Opcode) {

    case _WIN_SQUID_SERVICE_CONTROL_STOP:

    case _WIN_SQUID_SERVICE_CONTROL_SHUTDOWN:
        /* Do whatever it takes to stop here. */
        svcStatus.dwWin32ExitCode = 0;
        svcStatus.dwCurrentState = SERVICE_STOP_PENDING;
        svcStatus.dwCheckPoint = 0;
        svcStatus.dwWaitHint = 10000;
        shut_down(SIGTERM);

        if (!SetServiceStatus(svcHandle, &svcStatus)) {
            status = GetLastError();
            debug(1, 1) ("SetServiceStatus error %ld\n", status);
        }

        debug(1, 1) ("Leaving Squid service\n");
        return;

    case _WIN_SQUID_SERVICE_CONTROL_INTERROGATE:
        /* Fall through to send current status. */

        if (!SetServiceStatus(svcHandle, &svcStatus)) {
            status = GetLastError();
            debug(1, 1) ("SetServiceStatus error %ld\n", status);
        }

        break;

    case _WIN_SQUID_SERVICE_CONTROL_ROTATE:
        rotate_logs(SIGUSR1);
        break;

    case _WIN_SQUID_SERVICE_CONTROL_RECONFIGURE:
        reconfigure(SIGHUP);
        break;

    case _WIN_SQUID_SERVICE_CONTROL_DEBUG:
        sigusr2_handle(SIGUSR2);
        break;

    case _WIN_SQUID_SERVICE_CONTROL_INTERRUPT:
        /* Do whatever it takes to stop here. */
        svcStatus.dwWin32ExitCode = 0;
        svcStatus.dwCurrentState = SERVICE_STOP_PENDING;
        svcStatus.dwCheckPoint = 0;
        svcStatus.dwWaitHint = 10000;
        shut_down(SIGINT);

        if (!SetServiceStatus(svcHandle, &svcStatus)) {
            status = GetLastError();
            debug(1, 1) ("SetServiceStatus error %ld\n", status);
        }

        debug(1, 1) ("Leaving Squid service\n");
        break;

    default:
        debug(1, 1) ("Unrecognized opcode %ld\n", Opcode);
    }

    return;
}

void
WIN32_RemoveService()
{
    SC_HANDLE schService;
    SC_HANDLE schSCManager;

    if (!WIN32_Service_name)
        WIN32_Service_name = xstrdup(_WIN_SQUID_DEFAULT_SERVICE_NAME);

    strcat(REGKEY, WIN32_Service_name);

    keys[4] = WIN32_Service_name;

    schSCManager = OpenSCManager(NULL,	/* machine (NULL == local)    */
                                 NULL,			/* database (NULL == default) */
                                 SC_MANAGER_ALL_ACCESS	/* access required            */
                                );

    if (!schSCManager)
        fprintf(stderr, "OpenSCManager failed\n");
    else {
        schService = OpenService(schSCManager, WIN32_Service_name, SERVICE_ALL_ACCESS);

        if (schService == NULL)
            fprintf(stderr, "OpenService failed\n");

        /* Could not open the service */
        else {
            /* try to stop the service */

            if (ControlService(schService, _WIN_SQUID_SERVICE_CONTROL_STOP,
                               &svcStatus)) {
                sleep(1);

                while (QueryServiceStatus(schService, &svcStatus)) {
                    if (svcStatus.dwCurrentState == SERVICE_STOP_PENDING)
                        sleep(1);
                    else
                        break;
                }
            }

            /* now remove the service */
            if (DeleteService(schService) == 0)
                fprintf(stderr, "DeleteService failed.\n");
            else
                printf("Service %s deleted successfully.\n",
                       WIN32_Service_name);

            CloseServiceHandle(schService);
        }

        CloseServiceHandle(schSCManager);
    }
}

void
WIN32_SetServiceCommandLine()
{
    if (!WIN32_Service_name)
        WIN32_Service_name = xstrdup(_WIN_SQUID_DEFAULT_SERVICE_NAME);

    strcat(REGKEY, WIN32_Service_name);

    keys[4] = WIN32_Service_name;

    /* Now store the Service Command Line in the registry */
    WIN32_StoreKey(COMMANDLINE, REG_SZ, (unsigned char *) WIN32_Command_Line, strlen(WIN32_Command_Line) + 1);
}

void
WIN32_InstallService()
{
    SC_HANDLE schService;
    SC_HANDLE schSCManager;
    char ServicePath[512];
    char szPath[512];
    int lenpath;

    if (!WIN32_Service_name)
        WIN32_Service_name = xstrdup(_WIN_SQUID_DEFAULT_SERVICE_NAME);

    strcat(REGKEY, WIN32_Service_name);

    keys[4] = WIN32_Service_name;

    if ((lenpath = GetModuleFileName(NULL, ServicePath, 512)) == 0) {
        fprintf(stderr, "Can't get executable path\n");
        exit(1);
    }

    snprintf(szPath, sizeof(szPath), "%s %s:%s", ServicePath, _WIN_SQUID_SERVICE_OPTION, WIN32_Service_name);
    schSCManager = OpenSCManager(NULL,	/* machine (NULL == local)    */
                                 NULL,			/* database (NULL == default) */
                                 SC_MANAGER_ALL_ACCESS	/* access required            */
                                );

    if (!schSCManager) {
        fprintf(stderr, "OpenSCManager failed\n");
        exit(1);
    } else {
        schService = CreateService(schSCManager,    /* SCManager database     */
                                   WIN32_Service_name,			    /* name of service        */
                                   WIN32_Service_name,			    /* name to display        */
                                   SERVICE_ALL_ACCESS,			    /* desired access         */
                                   SERVICE_WIN32_OWN_PROCESS,		    /* service type           */
                                   SERVICE_AUTO_START,			    /* start type             */
                                   SERVICE_ERROR_NORMAL,		    /* error control type     */
                                   (const char *) szPath,		    /* service's binary       */
                                   NULL,				    /* no load ordering group */
                                   NULL,				    /* no tag identifier      */
                                   "Tcpip\0AFD\0",			    /* dependencies           */
                                   NULL,				    /* LocalSystem account    */
                                   NULL);				    /* no password            */

        if (schService) {
            if ((WIN32_OS_version == _WIN_OS_WIN2K) || (WIN32_OS_version == _WIN_OS_WINXP)
                    || (WIN32_OS_version == _WIN_OS_WINNET)) {
                HMODULE ADVAPI32Handle;
                PFChangeServiceConfig2 ChangeServiceConfig2;
                DWORD dwInfoLevel = SERVICE_CONFIG_DESCRIPTION;

                ADVAPI32Handle = GetModuleHandle("advapi32");
                ChangeServiceConfig2 = (PFChangeServiceConfig2) GetProcAddress(ADVAPI32Handle, CHANGESERVICECONFIG2);
                ChangeServiceConfig2(schService, dwInfoLevel, &Squid_ServiceDescription);
                dwInfoLevel = SERVICE_CONFIG_FAILURE_ACTIONS;
                ChangeServiceConfig2(schService, dwInfoLevel, &Squid_ServiceFailureActions);
            }

            CloseServiceHandle(schService);
            /* Now store the config file location in the registry */

            if (!ConfigFile)
                ConfigFile = xstrdup(DefaultConfigFile);

            WIN32_StoreKey(CONFIGFILE, REG_SZ, (unsigned char *) ConfigFile, strlen(ConfigFile) + 1);

            printf("Squid Cache version %s for %s\n", version_string,
                   CONFIG_HOST_TYPE);

            printf("installed successfully as %s Windows System Service.\n",
                   WIN32_Service_name);

            printf
            ("To run, start it from the Services Applet of Control Panel.\n");

            printf("Don't forget to edit squid.conf before starting it.\n\n");
        } else {
            fprintf(stderr, "CreateService failed\n");
            exit(1);
        }

        CloseServiceHandle(schSCManager);
    }
}

void
WIN32_sendSignal(int WIN32_signal)
{
    SERVICE_STATUS ssStatus;
    DWORD fdwAccess, fdwControl;
    SC_HANDLE schService;
    SC_HANDLE schSCManager;

    if (!WIN32_Service_name)
        WIN32_Service_name = xstrdup(_WIN_SQUID_DEFAULT_SERVICE_NAME);

    schSCManager = OpenSCManager(NULL,	/* machine (NULL == local)    */
                                 NULL,			/* database (NULL == default) */
                                 SC_MANAGER_ALL_ACCESS	/* access required            */
                                );

    if (!schSCManager) {
        fprintf(stderr, "OpenSCManager failed\n");
        exit(1);
    }

    /* The required service object access depends on the control. */
    switch (WIN32_signal) {

    case 0:			/* SIGNULL */
        fdwAccess = SERVICE_INTERROGATE;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_INTERROGATE;
        break;

    case SIGUSR1:
        fdwAccess = SERVICE_USER_DEFINED_CONTROL;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_ROTATE;
        break;

    case SIGUSR2:
        fdwAccess = SERVICE_USER_DEFINED_CONTROL;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_DEBUG;
        break;

    case SIGHUP:
        fdwAccess = SERVICE_USER_DEFINED_CONTROL;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_RECONFIGURE;
        break;

    case SIGTERM:
        fdwAccess = SERVICE_STOP;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_STOP;
        break;

    case SIGINT:

    case SIGKILL:
        fdwAccess = SERVICE_USER_DEFINED_CONTROL;
        fdwControl = _WIN_SQUID_SERVICE_CONTROL_INTERRUPT;
        break;

    default:
        exit(1);
    }

    /* Open a handle to the service. */
    schService = OpenService(schSCManager,	/* SCManager database */
                             WIN32_Service_name,	/* name of service    */
                             fdwAccess);		/* specify access     */

    if (schService == NULL) {
        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", appname,
                WIN32_Service_name);
        exit(1);
    } else {
        /* Send a control value to the service. */

        if (!ControlService(schService,	/* handle of service      */
                            fdwControl,	/* control value to send  */
                            &ssStatus)) {	/* address of status info */
            fprintf(stderr, "%s: ERROR: Could not Control Service %s\n",
                    appname, WIN32_Service_name);
            exit(1);
        } else {
            /* Print the service status. */
            printf("\nStatus of %s Service:\n", WIN32_Service_name);
            printf("  Service Type: 0x%lx\n", ssStatus.dwServiceType);
            printf("  Current State: 0x%lx\n", ssStatus.dwCurrentState);
            printf("  Controls Accepted: 0x%lx\n", ssStatus.dwControlsAccepted);
            printf("  Exit Code: %ld\n", ssStatus.dwWin32ExitCode);
            printf("  Service Specific Exit Code: %ld\n",
                   ssStatus.dwServiceSpecificExitCode);
            printf("  Check Point: %ld\n", ssStatus.dwCheckPoint);
            printf("  Wait Hint: %ld\n", ssStatus.dwWaitHint);
        }

        CloseServiceHandle(schService);
    }

    CloseServiceHandle(schSCManager);
}

int main(int argc, char **argv)
{
    SERVICE_TABLE_ENTRY DispatchTable[] = {
                                              {NULL, SquidMain},
                                              {NULL, NULL}
                                          };
    char *c;

    if ((argc == 2) && strstr(argv[1], _WIN_SQUID_SERVICE_OPTION)) {
        WIN32_run_mode = _WIN_SQUID_RUN_MODE_SERVICE;

        if (!(c=strchr(argv[1],':'))) {
            fprintf(stderr, "Bad Service Parameter: %s\n", argv[1]);
            return 1;
        }

        WIN32_Service_name = xstrdup(c+1);
        DispatchTable[0].lpServiceName=WIN32_Service_name;
        strcat(REGKEY, WIN32_Service_name);
        keys[4] = WIN32_Service_name;

        if (!StartServiceCtrlDispatcher(DispatchTable)) {
            fprintf(stderr, "StartServiceCtrlDispatcher error = %ld\n",
                    GetLastError());
            return 1;
        }
    } else {
        WIN32_run_mode = _WIN_SQUID_RUN_MODE_INTERACTIVE;
        SquidMain(argc, argv);
    }

    return 0;
}

#endif /* USE_WIN32_SERVICE */

#endif /* defined(_SQUID_MSWIN_) || defined(_SQUID_CYGWIN_) */

#endif /* WIN32_C */