
      for (idx = 1; idx < sync_mutex->idx; idx++)
        if (!streq (sync_mutex->list[0], sync_mutex->list[idx]))
          O (fatal, NILF, _("internal error: multiple --sync-mutex options"));

      /* Now parse the mutex handle string.  */
      mp = sync_mutex->list[0];
