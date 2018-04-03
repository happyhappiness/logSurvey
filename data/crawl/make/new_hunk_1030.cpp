    if (jobserver_fds->idx > 1)
      fatal (NILF, _("internal error: multiple --jobserver-fds options"));

    /* Now parse the fds string and make sure it has the proper format.  */

    cp = jobserver_fds->list[0];
