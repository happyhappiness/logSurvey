		} else {
			execvp(cmd->argv[0], (char *const*) cmd->argv);
		}
		trace_printf("trace: exec '%s' failed: %s\n", cmd->argv[0],
				strerror(errno));
		exit(127);
	}
#else
	int s0 = -1, s1 = -1, s2 = -1;	/* backups of stdin, stdout, stderr */
