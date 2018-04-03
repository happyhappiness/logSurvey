            puts("ERR");
            continue;
        }

        rfc1738_unescape(username);
        rfc1738_unescape(password);

        if (validate_user(username, password)) {
            puts("OK");
        } else {
            syslog(LOG_INFO, "'%s' login failed", username);
            puts("ERR");
        }
