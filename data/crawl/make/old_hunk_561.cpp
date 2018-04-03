   Append "(ignored)" if IGNORED is nonzero.  */

static void
child_error (const char *target_name,
             int exit_code, int exit_sig, int coredump, int ignored)
{
  if (ignored && silent_flag)
    return;

#ifdef VMS
  if (!(exit_code & 1))
      error (NILF,
             (ignored ? _("*** [%s] Error 0x%x (ignored)")
              : _("*** [%s] Error 0x%x")),
             target_name, exit_code);
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

