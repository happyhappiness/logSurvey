	    int x;
	    while ((x = read(put_fd, msg, BUFSIZ)) > 0) {
		x = write(conn, msg, x);
		total_bytes += x;
		if (x <= 0)
		    break;
	    }
	    if (x != 0)
		fprintf(stderr, "client: ERROR: Cannot send file.\n");
	    close(put_fd);
	}
	/* Read the data */
