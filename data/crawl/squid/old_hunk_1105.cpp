            puts("ERR");
            continue;
        }
        Checktimer();		/* Check if the user lists have changed */

        rfc1738_unescape(username);
        rfc1738_unescape(password);
