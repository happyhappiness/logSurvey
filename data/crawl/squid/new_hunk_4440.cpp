
    for (i = 0; loops == 0 || i < loops; i++) {
	int fsize = 0;
        struct addrinfo *AI = NULL;

	/* Connect to the server */

        if(localhost) {
            if( !iaddr.GetHostByName(localhost) ) {
                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", localhost);
                exit(1);
            }
        }
        else {
            /* Process the remote host name to locate the Protocol required
               in case we are being asked to link to another version of squid */
            if( !iaddr.GetHostByName(hostname) ) {
                fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
                exit(1);
            }
        }

        iaddr.GetAddrInfo(AI);
        if ((conn = socket(AI->ai_family, AI->ai_socktype, 0)) < 0) {
            perror("client: socket");
            iaddr.FreeAddrInfo(AI);
            exit(1);
        }
        iaddr.FreeAddrInfo(AI);

        if (localhost && client_comm_bind(conn, iaddr) < 0) {
            perror("client: bind");
            exit(1);
        }

        iaddr.SetEmpty();
         if( !iaddr.GetHostByName(hostname) ) {
            fprintf(stderr, "client: ERROR: Cannot resolve %s: Host unknown.\n", hostname);
            exit(1);
        }

        iaddr.SetPort(port);

        if (client_comm_connect(conn, iaddr, ping ? &tv1 : NULL) < 0) {
            char buf[MAX_IPSTRLEN];
            iaddr.ToURL(buf, MAX_IPSTRLEN);
            if (errno == 0) {
                fprintf(stderr, "client: ERROR: Cannot connect to %s: Host unknown.\n", buf);
            } else {
                char tbuf[BUFSIZ];
                snprintf(tbuf, BUFSIZ, "client: ERROR: Cannot connect to %s", buf);
                perror(tbuf);
            }
            exit(1);
        }

	/* Send the HTTP request */
	bytesWritten = mywrite(conn, msg, strlen(msg));

