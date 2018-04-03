	    exit(1);
	}
	if (put_file) {
		int x;
		while ((x=read(put_fd,msg, BUFSIZ))>0) {
				x=write(conn, msg, x);
				if (x<=0) break;
		} 
		if (x!=0) {
			fprintf(stderr,"client: ERROR: Cannot send file.\n");
			exit(1);
		}
		close(put_fd);
	}
	/* Read the data */
	while ((len = read(conn, buf, sizeof(buf))) > 0) {
