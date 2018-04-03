  decode_env_switches ("MFLAGS", 6);
#endif

#ifdef __MSDOS__
  if (job_slots != 1)
    {
      error (NILF,
             _("Parallel jobs (-j) are not supported on this platform."));
