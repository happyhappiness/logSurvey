
#ifdef VMS
  if (!(exit_code & 1))
      error (NILF, _("*** [%s] Error 0x%x%s"), target_name, exit_code, ((ignored)? _(" (ignored)") : ""));
#else
  if (exit_sig == 0)
    error (NILF, ignored ? _("[%s] Error %d (ignored)") :
	   _("*** [%s] Error %d"),
	   target_name, exit_code);
  else
    error (NILF, "*** [%s] %s%s",
	   target_name, strsignal (exit_sig),
	   coredump ? _(" (core dumped)") : "");
#endif /* VMS */
}

