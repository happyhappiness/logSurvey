    }
}

static void
decode_output_sync_flags (void)
{
  const char **pp;

  if (!output_sync_option)
    return;

  for (pp=output_sync_option->list; *pp; ++pp)
    {
      const char *p = *pp;

      if (streq (p, "target"))
        output_sync = OUTPUT_SYNC_TARGET;
      else if (streq (p, "make"))
        output_sync = OUTPUT_SYNC_MAKE;
      else
        fatal (NILF, _("unknown output-sync type '%s'"), p);
    }
}

#ifdef WINDOWS32
/*
 * HANDLE runtime exceptions by avoiding a requestor on the GUI. Capture
