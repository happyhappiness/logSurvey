                             fdwAccess);		/* specify access     */

    if (schService == NULL) {
        fprintf(stderr, "%s: ERROR: Could not open Service %s\n", appname,
                WIN32_Service_name);
        exit(1);
    } else {
