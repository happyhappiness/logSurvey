          break;
      else
	{
	  char *pidstr = xstrdup (pid2str ((DWORD_PTR)hWaitPID));

          fprintf(stderr,
                  _("make reaped child pid %s, still waiting for pid %s\n"),
		  pidstr, pid2str ((DWORD_PTR)hPID));
	  free (pidstr);
	}
    }
