     int exit_code, exit_sig, coredump;
     int ignored;
{
  if (exit_sig == 0)
    error (ignored ? "[%s] Error %d (ignored)" :
	   "*** [%s] Error %d%s",
	   target_name, exit_code);
  else
    {
      char *coredump_string = coredump ? " (core dumped)" : "";
