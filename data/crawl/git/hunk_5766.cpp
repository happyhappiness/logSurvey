 		if (code == 127) {
 			code = -1;
 			failed_errno = ENOENT;
+			if (!silent_exec_failure)
+				error("cannot run %s: %s", argv0,
+					strerror(ENOENT));
 		}
 	} else {
 		error("waitpid is confused (%s)", argv0);
