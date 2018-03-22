	{
	  int sig = WTERMSIG (wait_status);
	  if (!(!eof && sig == SIGPIPE))
	    FATAL_ERROR ((0, 0, _("Child died with signal %d"), sig));
	}
      else if (WEXITSTATUS (wait_status) != 0)
	FATAL_ERROR ((0, 0, _("Child returned status %d"),
		      WEXITSTATUS (wait_status)));
    }
}

