          break;
      else
	{
	  char *pidstr = xstrdup (pid2str ((pid_t)hWaitPID));

          fprintf(stderr,
                  _("make reaped child pid %s, still waiting for pid %s\n"),
		  pidstr, pid2str ((pid_t)hPID));
	  free (pidstr);
	}
    }
