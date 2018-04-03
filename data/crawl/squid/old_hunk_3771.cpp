        }
        if (err) {
            syslog(LOG_WARNING, "oversized message");
            goto error;
        }

        /*
