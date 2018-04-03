            fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
            exit(1);
        }
        fprintf(stderr, "done.\n");

        if (put_file) {
            fprintf(stderr, "Sending HTTP request payload ... ");
            int x;
            lseek(put_fd, 0, SEEK_SET);
            while ((x = read(put_fd, buf, sizeof(buf))) > 0) {
