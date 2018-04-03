    error ("*** [%s] %s%s",
	   target_name, strsignal (exit_sig),
	   coredump ? " (core dumped)" : "");
}

static unsigned int dead_children = 0;

/* Notice that a child died.
   reap_children should be called when convenient.  */
RETSIGTYPE
