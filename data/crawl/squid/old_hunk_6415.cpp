	    if (FD[i].cb == NULL)
		continue;
	    if (now.tv_sec - FD[i].start > lifetime) {
		fd_close(i);
		continue;
	    }