#if defined (SIGNOFP)
  init_sig (SIGNOFP, "NOFP", _("Floating point co-processor not available"));
#endif

  return 1;
}

#endif  /* SYS_SIGLIST_DECLARED */


char *
strsignal (signal)
