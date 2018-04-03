	memFree(MEM_8K_BUF, redirector->inbuf);
	redirector->inbuf = NULL;
	comm_close(fd);
	return;
    }
    if (len != 1)
