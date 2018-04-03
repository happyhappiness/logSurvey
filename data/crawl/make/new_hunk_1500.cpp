	   "*** [%s] Error %d",
	   target_name, exit_code);
  else
    error ("*** [%s] %s%s",
	   target_name, strsignal (exit_sig),
	   coredump ? " (core dumped)" : "");
}

static unsigned int dead_children = 0;
