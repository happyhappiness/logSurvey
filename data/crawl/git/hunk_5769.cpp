 	} else if (waiting != pid) {
 		error("waitpid is confused (%s)", argv0);
 	} else if (WIFSIGNALED(status)) {
-		error("%s died of signal", argv0);
+		code = WTERMSIG(status);
+		error("%s died of signal %d", argv0, code);
+		/*
+		 * This return value is chosen so that code & 0xff
+		 * mimics the exit code that a POSIX shell would report for
+		 * a program that died from this signal.
+		 */
+		code -= 128;
 	} else if (WIFEXITED(status)) {
 		code = WEXITSTATUS(status);
 		/*