 			git_tcp_connect(fd, host, flags);
 		/*
 		 * Separate original protocol components prog and path
-		 * from extended components with a NUL byte.
+		 * from extended host header with a NUL byte.
+		 *
+		 * Note: Do not add any other headers here!  Doing so
+		 * will cause older git-daemon servers to crash.
 		 */
 		packet_write(fd[1],
 			     "%s %s%chost=%s%c",
