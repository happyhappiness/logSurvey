    assert(hlp->n_running >= 0);

    if (!srv->flags.shutdown) {
        debug(84, 0) ("WARNING: %s #%d (FD %d) exited\n",
                      hlp->id_name, srv->index + 1, fd);

        if (hlp->n_running < hlp->n_to_start / 2)
            fatalf("Too few %s processes are running", hlp->id_name);
    }

    cbdataReferenceDone(srv->parent);
