        debug(84, 0) ("WARNING: %s #%d (FD %d) exited\n",
                      hlp->id_name, srv->index + 1, fd);

        if (hlp->n_active < hlp->n_to_start / 2) {
            debug(80, 0) ("Too few %s processes are running\n", hlp->id_name);

            if (hlp->last_restart > squid_curtime - 30)
                fatalf("The %s helpers are crashing too rapidly, need help!\n", hlp->id_name);

            debug(80, 0) ("Starting new helpers\n");

            helperOpenServers(hlp);
        }
    }

    cbdataReferenceDone(srv->parent);
