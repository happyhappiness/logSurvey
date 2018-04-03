	    fprintf(stderr, "client: ERROR: Cannot send request?: %s\n", msg);
	    exit(1);
	}
	if (put_file) {
	    int x;
	    lseek(put_fd, 0, SEEK_SET);
