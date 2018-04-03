    assert(hlp->n_running >= 0);

    if (!srv->flags.shutdown) {
        hlp->n_active--;
        assert( hlp->n_active >= 0);
        debug(84, 0) ("WARNING: %s #%d (FD %d) exited\n",
                      hlp->id_name, srv->index + 1, fd);

        if (hlp->n_active < hlp->n_to_start / 2)
            fatalf("Too few %s processes are running\n", hlp->id_name);
    }

    if (srv->data != NULL)
