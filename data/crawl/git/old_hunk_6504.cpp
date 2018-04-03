		} else {
			execvp(cmd->argv[0], (char *const*) cmd->argv);
		}
		die("exec %s failed.", cmd->argv[0]);
	}
#else
	int s0 = -1, s1 = -1, s2 = -1;	/* backups of stdin, stdout, stderr */
