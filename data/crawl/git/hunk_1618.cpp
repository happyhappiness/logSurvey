 	else if (is_absolute_path(trace)) {
 		int fd = open(trace, O_WRONLY | O_APPEND | O_CREAT, 0666);
 		if (fd == -1) {
-			fprintf(stderr,
-				"Could not open '%s' for tracing: %s\n"
-				"Defaulting to tracing on stderr...\n",
+			warning("Could not open '%s' for tracing: %s\n"
+				"Defaulting to tracing on stderr...",
 				trace, strerror(errno));
 			key->fd = STDERR_FILENO;
 		} else {
 			key->fd = fd;
 			key->need_close = 1;
 		}
 	} else {
-		fprintf(stderr, "What does '%s' for %s mean?\n"
+		warning("What does '%s' for %s mean?\n"
 			"If you want to trace into a file, then please set "
 			"%s to an absolute pathname (starting with /).\n"
-			"Defaulting to tracing on stderr...\n",
+			"Defaulting to tracing on stderr...",
 			trace, key->key, key->key);
 		key->fd = STDERR_FILENO;
 	}
