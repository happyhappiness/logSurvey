  decode_env_switches ("MFLAGS", 6);
#endif

#if defined (__MSDOS__) || defined (__EMX__)
  if (job_slots != 1
# ifdef __EMX__
      && _osmode != OS2_MODE /* turn off -j if we are in DOS mode */
# endif
      )
    {
      error (NILF,
             _("Parallel jobs (-j) are not supported on this platform."));
