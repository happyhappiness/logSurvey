        }
        if (err) {
            syslog(LOG_WARNING, "oversized message");
            puts("ERR");
            err = 0;
            continue;
        }

        /*
