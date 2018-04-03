    }
    NRedirectors = getRedirectChildren();
    redirect_child_table = xcalloc(NRedirectors, sizeof(redirector_t *));
    debug(14, 1, "redirectOpenServers: Starting %d '%s' processes\n",
	NRedirectors, prg);
    for (k = 0; k < NRedirectors; k++) {
	redirect_child_table[k] = xcalloc(1, sizeof(redirector_t));
	if ((redirectsocket = redirectCreateRedirector(prg)) < 0) {
	    debug(14, 1, "WARNING: Cannot run '%s' process.\n", prg);
	    redirect_child_table[k]->flags &= ~REDIRECT_FLAG_ALIVE;
	} else {
	    redirect_child_table[k]->flags |= REDIRECT_FLAG_ALIVE;
	    redirect_child_table[k]->index = k;
	    redirect_child_table[k]->fd = redirectsocket;
	    sprintf(fd_note_buf, "%s #%d",
		prg,
		redirect_child_table[k]->index + 1);
	    fd_note(redirect_child_table[k]->fd, fd_note_buf);
	    commSetNonBlocking(redirect_child_table[k]->fd);

	    /* set handler for incoming result */
	    comm_set_select_handler(redirect_child_table[k]->fd,
		COMM_SELECT_READ,
		(PF) redirectHandleRead,
		(void *) redirect_child_table[k]);
	    debug(14, 3, "redirectOpenServers: 'redirect_server' %d started\n",
		k);
	}
    }
}

int redirectUnregister(url, fd)
     char *url;
     int fd;
{
    return 0;
}

void redirectShutdownServers()
{
    redirector_t *redirector = NULL;
    int k;
    static char *shutdown = "$shutdown\n";

    debug(14, 3, "redirectShutdownServers:\n");

    for (k = 0; k < getRedirectChildren(); k++) {
	redirector = *(redirect_child_table + k);
	debug(14, 3, "redirectShutdownServers: sending '$shutdown' to redirector #%d\n", k);
	debug(14, 3, "redirectShutdownServers: --> FD %d\n", redirector->fd);
	comm_write(redirector->fd,
	    xstrdup(shutdown),
	    strlen(shutdown),
	    0,			/* timeout */
	    NULL,		/* Handler */
	    NULL);		/* Handler-data */
	redirector->flags |= REDIRECT_FLAG_CLOSING;
    }
}
