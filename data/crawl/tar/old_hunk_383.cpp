      while (waitpid (child_pid, &wait_status, 0) == -1)
	if (errno != EINTR)
	  {
	    ERROR ((0, errno, _("While waiting for child")));
	    break;
	  }

