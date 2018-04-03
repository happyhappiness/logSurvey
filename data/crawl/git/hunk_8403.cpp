 		usage(send_pack_usage);
 	verify_remote_names(nr_heads, heads);
 
+	if (remote_name) {
+		remote = remote_get(remote_name);
+		if (!remote_has_uri(remote, dest)) {
+			die("Destination %s is not a uri for %s",
+			    dest, remote_name);
+		}
+	}
+
 	pid = git_connect(fd, dest, receivepack, verbose ? CONNECT_VERBOSE : 0);
 	if (pid < 0)
 		return 1;
-	ret = send_pack(fd[0], fd[1], nr_heads, heads);
+	ret = send_pack(fd[0], fd[1], remote, nr_heads, heads);
 	close(fd[0]);
 	close(fd[1]);
 	ret |= finish_connect(pid);