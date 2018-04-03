      else
        fatal (NILF, _("unknown output-sync type '%s'"), p);
    }

  if (sync_mutex)
    {
      const char *mp;
      unsigned int idx;

      for (idx = 1; idx < sync_mutex->idx; idx++)
        if (!streq (sync_mutex->list[0], sync_mutex->list[idx]))
          fatal (NILF, _("internal error: multiple --sync-mutex options"));

      /* Now parse the mutex handle string.  */
      mp = sync_mutex->list[0];
      RECORD_SYNC_MUTEX (mp);
    }
}

#ifdef WINDOWS32

/* This is called from start_job_command when it detects that
   output_sync option is in effect.  The handle to the synchronization
   mutex is passed, as a string, to sub-makes via the --sync-mutex
   command-line argument.  */
void
prepare_mutex_handle_string (sync_handle_t handle)
{
  if (!sync_mutex)
    {
      /* 2 hex digits per byte + 2 characters for "0x" + null.  */
      char hdl_string[2 * sizeof (sync_handle_t) + 2 + 1];

      /* Prepare the mutex handle string for our children.  */
      sprintf (hdl_string, "0x%x", handle);
      sync_mutex = xmalloc (sizeof (struct stringlist));
      sync_mutex->list = xmalloc (sizeof (char *));
      sync_mutex->list[0] = xstrdup (hdl_string);
      sync_mutex->idx = 1;
      sync_mutex->max = 1;
      define_makeflags (1, 0);
    }
}

/*
 * HANDLE runtime exceptions by avoiding a requestor on the GUI. Capture
 * exception and print it to stderr instead.
