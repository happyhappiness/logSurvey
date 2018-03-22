		spawnl (P_WAIT, getenv ("COMSPEC"), "-", 0);
#else /* not MSDOS */
		{
		  pid_t child = fork ();
		  switch (child)
		    {
		    case -1:
		      WARN ((0, errno, _("Cannot fork!")));
		      break;

		    case 0:
		      {
			const char *shell = getenv ("SHELL");
			
			if (! shell)
			  shell = "/bin/sh";
			execlp (shell, "-sh", "-i", 0);
			FATAL_ERROR ((0, errno, _("Cannot exec a shell %s"),
				      shell));
		      }

		    default:
		      {
			int wait_status;
			while (waitpid (child, &wait_status, 0) == -1)
			  if (errno != EINTR)
			    {
			      ERROR ((0, errno,
				      _("While waiting for child")));
			      break;
			    }
		      }
		      break;
		    }
		}
#endif /* not MSDOS */
