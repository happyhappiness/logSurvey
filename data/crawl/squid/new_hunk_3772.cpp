            puts("OK");
        else {
            syslog(LOG_INFO, "'%s' login failed", username);
            puts("ERR");
        }
        err = 0;