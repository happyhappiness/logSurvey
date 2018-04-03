
      for (ui=1; ui < jobserver_fds->idx; ++ui)
        if (!streq (jobserver_fds->list[0], jobserver_fds->list[ui]))
          fatal (NILF, _("internal error: multiple --jobserver-fds options"));

      /* Now parse the fds string and make sure it has the proper format.  */

