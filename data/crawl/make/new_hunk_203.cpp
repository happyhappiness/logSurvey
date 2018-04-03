      else if (streq (p, "recurse"))
        output_sync = OUTPUT_SYNC_RECURSE;
      else
        OS (fatal, NILF, _("unknown output-sync type '%s'"), p);
    }

  if (sync_mutex)
