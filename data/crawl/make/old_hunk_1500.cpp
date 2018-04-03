	   "*** [%s] Error %d",
	   target_name, exit_code);
  else
    {
      char *coredump_string = coredump ? " (core dumped)" : "";
      if (exit_sig > 0 && exit_sig < NSIG)
	error ("*** [%s] %s%s",
	       target_name, sys_siglist[exit_sig], coredump_string);
      else
	error ("*** [%s] Signal %d%s", target_name, exit_sig, coredump_string);
    }
}

static unsigned int dead_children = 0;
