		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
#else /* not MSDOS */
		{
		  pid_t child;
		  const char *shell = getenv ("SHELL");
		  if (! shell)
		    shell = "/bin/sh";
		  child = xfork ();
		  if (child == 0)
		    {
		      execlp (shell, "-sh", "-i", 0);
		      exec_fatal (shell);
		    }
		  else
		    {
		      int wait_status;
		      while (waitpid (child, &wait_status, 0) == -1)
			if (errno != EINTR)
			  {
			    waitpid_error (shell);
			    break;
			  }
		    }
		}
#endif /* not MSDOS */
