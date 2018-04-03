            puts("ERR");
            continue;
        }
        Checktimer();		/* Check if the user lists have changed */

        rfc1738_unescape(username);
        rfc1738_unescape(password);

        /*
         * Check if user is explicitly denied or allowed.
         * If user passes both checks, they can be authenticated.
         */
        if (Check_user(username) == 1) {
            syslog(LOG_INFO, "'%s' denied", username);
            puts("ERR");
        } else if (QueryServers(username, password) == 0)
            puts("OK");
        else {
            syslog(LOG_INFO, "'%s' login failed", username);
            puts("ERR");
        }
