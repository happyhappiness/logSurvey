 		die("fetch-pack: unable to fork off %s", argv[0]);
 	if (!pid) {
 		dup2(fd[0], 0);
+		if (do_keep && pack_lockfile) {
+			dup2(keep_pipe[1], 1);
+			close(keep_pipe[0]);
+			close(keep_pipe[1]);
+		}
 		close(fd[0]);
 		close(fd[1]);
 		execv_git_cmd(argv);
 		die("%s exec failed", argv[0]);
 	}
 	close(fd[0]);
 	close(fd[1]);
+	if (do_keep && pack_lockfile) {
+		close(keep_pipe[1]);
+		*pack_lockfile = index_pack_lockfile(keep_pipe[0]);
+		close(keep_pipe[0]);
+	}
 	while (waitpid(pid, &status, 0) < 0) {
 		if (errno != EINTR)
 			die("waiting for %s: %s", argv[0], strerror(errno));
