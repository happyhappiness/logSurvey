         *    Send the request we've built.
         */
        gettimeofday(&sent, NULL);
        send(socket_fd, (char *) auth, total_length, 0);
        while ((time_spent = time_since(&sent)) < 1000000) {
            struct timeval tv;
            int rc, len;
