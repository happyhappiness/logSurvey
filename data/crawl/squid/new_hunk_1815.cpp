         *    Send the request we've built.
         */
        gettimeofday(&sent, NULL);
        if (send(socket_fd, (char *) auth, total_length, 0) < 0) {
            // EAGAIN is expected at high traffic, just retry
            // TODO: block/sleep a few ms to let the apparently full buffer drain ?
            if (errno != EAGAIN && errno != EWOULDBLOCK)
                fprintf(stderr,"ERROR: RADIUS send() failure: %s\n", xstrerror());
            continue;
        }
        while ((time_spent = time_since(&sent)) < 1000000) {
            struct timeval tv;
            int rc, len;
