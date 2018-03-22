	  }

      if (WIFSIGNALED (wait_status))
	{
	  /* SIGPIPE is OK, everything else is a problem.  */
	  
	  if (WTERMSIG (wait_status) != SIGPIPE)
	    ERROR ((0, 0, _("Child died with signal %d"),
		    WTERMSIG (wait_status)));
	}
      else
	{
	  /* Child voluntarily terminated -- but why?  /bin/sh returns
	     SIGPIPE + 128 if its child, then do nothing.  */
	      
	  if (WEXITSTATUS (wait_status)
	      && WEXITSTATUS (wait_status) != (SIGPIPE + 128))
	    ERROR ((0, 0, _("Child returned status %d"),
		    WEXITSTATUS (wait_status)));
	}
    }
#endif /* !MSDOS */

