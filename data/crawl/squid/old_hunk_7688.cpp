	    fd, redirector->index + 1);
	redirector->flags = 0;
	comm_close(fd);
	return 0;
    }
    redirector->offset += len;
