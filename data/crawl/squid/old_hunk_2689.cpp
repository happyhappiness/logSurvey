        user = strtok(buf, " \r\n");
        passwd = strtok(NULL, "\r\n");

        if (!user || !passwd || !passwd[0]) {
            printf("ERR\n");
            continue;
        }
        rfc1738_unescape(user);
        rfc1738_unescape(passwd);
        if (!validUsername(user)) {
            printf("ERR No such user\n");
            continue;
        }
        tryagain = (ld != NULL);