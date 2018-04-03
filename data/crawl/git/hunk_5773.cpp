 				strerror(errno));
 		exit(127);
 	}
+	if (cmd->pid < 0)
+		error("cannot fork() for %s: %s", cmd->argv[0],
+			strerror(failed_errno = errno));
 #else
 	int s0 = -1, s1 = -1, s2 = -1;	/* backups of stdin, stdout, stderr */
 	const char **sargv = cmd->argv;
