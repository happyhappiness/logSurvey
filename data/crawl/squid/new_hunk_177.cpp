         */
        gettimeofday(&sent, NULL);
        if (send(socket_fd, (char *) auth, total_length, 0) < 0) {
            int xerrno = errno;
            // EAGAIN is expected at high traffic, just retry
            // TODO: block/sleep a few ms to let the apparently full buffer drain ?
            if (xerrno != EAGAIN && xerrno != EWOULDBLOCK)
                fprintf(stderr,"ERROR: RADIUS send() failure: %s\n", xstrerr(xerrno));
            continue;
        }
        while ((time_spent = time_since(&sent)) < 1000000) {
