       }
    }

    if(version[0] == '-') {
        snprintf(msg, BUFSIZ, "%s %s\r\n", method, url);
    } else {
        snprintf(msg, BUFSIZ, "%s %s HTTP/%s\r\n", method, url, version);
    }

    if (host) {
        snprintf(buf, BUFSIZ, "Host: %s\r\n", host);
        strcat(msg,buf);
    }

    if (reload) {
        snprintf(buf, BUFSIZ, "Pragma: no-cache\r\n");
        strcat(msg, buf);
    }
    if (put_fd > 0) {
        snprintf(buf, BUFSIZ, "Content-length: %d\r\n", (int) sb.st_size);
        strcat(msg, buf);
    }
    if (opt_noaccept == 0) {
        snprintf(buf, BUFSIZ, "Accept: */*\r\n");
        strcat(msg, buf);
    }
    if (ims) {
        snprintf(buf, BUFSIZ, "If-Modified-Since: %s\r\n", mkrfc1123(ims));
        strcat(msg, buf);
    }
    if (max_forwards > -1) {
        snprintf(buf, BUFSIZ, "Max-Forwards: %d\r\n", max_forwards);
        strcat(msg, buf);
    }
    if (proxy_user) {
        const char *user = proxy_user;
        const char *password = proxy_password;
#if HAVE_GETPASS

        if (!password)
            password = getpass("Proxy password: ");

#endif

        if (!password) {
            fprintf(stderr, "ERROR: Proxy password missing\n");
            exit(1);
        }
        snprintf(buf, BUFSIZ, "%s:%s", user, password);
        snprintf(buf, BUFSIZ, "Proxy-Authorization: Basic %s\r\n", base64_encode(buf));
        strcat(msg, buf);
    }
    if (www_user) {
        const char *user = www_user;
        const char *password = www_password;
#if HAVE_GETPASS

        if (!password)
            password = getpass("WWW password: ");

#endif

        if (!password) {
            fprintf(stderr, "ERROR: WWW password missing\n");
            exit(1);
        }
        snprintf(buf, BUFSIZ, "%s:%s", user, password);
        snprintf(buf, BUFSIZ, "Authorization: Basic %s\r\n", base64_encode(buf));
        strcat(msg, buf);
    }

    /* 1.0 & 1.1 might need Proxy-Connection: header */
    if (version[0] == '1' && version[1] == '.' &&  version[2] >= '0' && version[2] <= '1') {
        if (keep_alive) {
            if (port != 80)
                snprintf(buf, BUFSIZ, "Proxy-Connection: keep-alive\r\n");
            else
               strcat(msg, "Connection: keep-alive\r\n");
       }
     } else {
        if (!keep_alive)
            strcat(msg, "Connection: close\r\n");
        else
            snprintf(buf, BUFSIZ, "Connection: keep-alive\r\n");
    }
    strcat(msg, buf);

    strcat(msg, extra_hdrs);
    strcat(msg, "\r\n");

    if (opt_verbose)
        fprintf(stderr, "headers: '%s'\n", msg);

    if (ping) {
#if HAVE_SIGACTION