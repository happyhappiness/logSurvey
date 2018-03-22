	  }

      if (WIFSIGNALED (wait_status))
	ERROR ((0, 0, _("Child died with signal %d"),
		WTERMSIG (wait_status)));
      else if (WEXITSTATUS (wait_status) != 0)
	ERROR ((0, 0, _("Child returned status %d"),
		WEXITSTATUS (wait_status)));
