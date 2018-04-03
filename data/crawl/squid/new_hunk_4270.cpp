                            fdwControl,	/* control value to send  */
                            &ssStatus)) {	/* address of status info */
            fprintf(stderr, "%s: ERROR: Could not Control Service %s\n",
                    APP_SHORTNAME, WIN32_Service_name);
            exit(1);
        } else {
            /* Print the service status. */
