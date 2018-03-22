	{
	  int sig = WTERMSIG (wait_status);
	  if (!(!eof && sig == SIGPIPE))
	    ERROR ((0, 0, _("Child died with signal %d"), sig));
	}
      else if (WEXITSTATUS (wait_status) != 0)
	ERROR ((0, 0, _("Child returned status %d"),
		WEXITSTATUS (wait_status)));
    }
}

