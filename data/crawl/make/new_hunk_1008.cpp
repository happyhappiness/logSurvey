  {
    char *cp;

    for (i=1; i < jobserver_fds->idx; ++i)
      if (!streq (jobserver_fds->list[0], jobserver_fds->list[i]))
        fatal (NILF, _("internal error: multiple --jobserver-fds options"));

    /* Now parse the fds string and make sure it has the proper format.  */

