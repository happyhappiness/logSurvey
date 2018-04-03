    if (srv->wfd != srv->rfd)
	comm_close(srv->wfd);
    dlinkDelete(&srv->link, &hlp->servers);
    hlp->n_running--;
    assert(hlp->n_running >= 0);
    if (!shutting_down && !reconfiguring) {
        debug(34, 0) ("WARNING: %s #%d (FD %d) exited\n",
	    hlp->id_name, srv->index + 1, fd);
        if (hlp->n_running < hlp->n_to_start / 2)
	    fatalf("Too few %s processes are running", hlp->id_name);
    }
    cbdataFree(srv);
}

static void