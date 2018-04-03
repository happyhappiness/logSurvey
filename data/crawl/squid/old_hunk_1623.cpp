
    /* Open a handle to the service. */
    schService = OpenService(schSCManager,	/* SCManager database */
                             WIN32_Service_name,	/* name of service    */
                             fdwAccess);		/* specify access     */

    if (schService == NULL) {
        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", APP_SHORTNAME,
                WIN32_Service_name);
        exit(1);
    } else {
        /* Send a control value to the service. */
