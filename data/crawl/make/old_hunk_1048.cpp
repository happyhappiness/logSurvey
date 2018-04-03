  {
    char *cp;

    if (jobserver_fds->max > 1)
      fatal (NILF, _("internal error: multiple --jobserver-fds options."));

    if (job_slots > 0)
      fatal (NILF, _("internal error: --jobserver-fds unexpected."));

    /* Now parse the fds string and make sure it has the proper format.  */

