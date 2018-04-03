# endif
      )
    {
      error (NILF,
             _("Parallel jobs (-j) are not supported on this platform."));
      error (NILF, _("Resetting to single job (-j1) mode."));
      job_slots = 1;
    }
#endif
