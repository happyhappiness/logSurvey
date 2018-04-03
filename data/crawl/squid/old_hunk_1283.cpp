
    /* Open a handle to the service. */
    schService = OpenService(schSCManager,	/* SCManager database */
                             service_name,	/* name of service    */
                             fdwAccess);		/* specify access     */

    if (schService == NULL) {
        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", APP_SHORTNAME, service_name);
        exit(1);
    } else {
        /* Send a control value to the service. */

        if (!ControlService(schService,	/* handle of service      */
                            fdwControl,	/* control value to send  */
                            &ssStatus)) {	/* address of status info */
            fprintf(stderr, "%s: ERROR: Could not Control Service %s\n",
                    APP_SHORTNAME, service_name);
            exit(1);
        } else {
            /* Print the service status. */
            printf("\nStatus of %s Service:\n", service_name);
            printf("  Service Type: 0x%lx\n", ssStatus.dwServiceType);
            printf("  Current State: 0x%lx\n", ssStatus.dwCurrentState);
            printf("  Controls Accepted: 0x%lx\n", ssStatus.dwControlsAccepted);