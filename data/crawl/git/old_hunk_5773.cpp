				strerror(errno));
		exit(127);
	}
#else
	int s0 = -1, s1 = -1, s2 = -1;	/* backups of stdin, stdout, stderr */
	const char **sargv = cmd->argv;
