    total_length += 6;

    if (*identifier) {
        int len = strlen(identifier);
        *ptr++ = PW_NAS_ID;
        *ptr++ = len + 2;
        memcpy(ptr, identifier, len);
        ptr += len;
    } else {
        *ptr++ = PW_NAS_IP_ADDRESS;
        *ptr++ = 6;

        ui = htonl(nas_ipaddr);
        memcpy(ptr, &ui, 4);
        ptr += 4;
        total_length += 6;
    }

    /* Klaus Weidner <kw@w-m-p.com> changed this
     * from htonl to htons. It might have caused
     * you trouble or not. That depends on the byte
     * order of your system.
     * The symptom was that the radius server
     * ignored the requests, because they had zero
     * length according to the data header.
     */
    auth->length = htons(total_length);

    while (retry--) {
        int time_spent;
        struct timeval sent;
        /*
         *    Send the request we've built.
         */
        gettimeofday(&sent, NULL);
        send(sockfd, (char *) auth, total_length, 0);
        while ((time_spent = time_since(&sent)) < 1000000) {
            struct timeval tv;
            int rc, len;
            if (!time_spent) {
                tv.tv_sec = 1;
                tv.tv_usec = 0;
            } else {
                tv.tv_sec = 0;
                tv.tv_usec = 1000000 - time_spent;
            }
            FD_ZERO(&readfds);
            FD_SET(sockfd, &readfds);
            if (select(sockfd + 1, &readfds, NULL, NULL, &tv) == 0)	/* Select timeout */
                break;
            salen = sizeof(saremote);
            len = recvfrom(sockfd, recv_buffer, sizeof(i_recv_buffer),
                           0, (struct sockaddr *) &saremote, &salen);

            if (len < 0)
                continue;

            rc = result_recv(saremote.sin_addr.s_addr, saremote.sin_port, recv_buffer, len);
            if (rc == 0)
                return 1;
            if (rc == 1)
                return 0;
        }
    }

    fprintf(stderr, "%s: No response from RADIUS server\n", progname);
