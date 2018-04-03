 					die("could not open '%s': %s",
 						argv[i], strerror(errno));
 			}
-			len = 1024;
-			message = xmalloc(len);
-			if (read_fd(fd, &message, &len)) {
-				free(message);
+			if (strbuf_read(&buf, fd, 1024) < 0) {
 				die("cannot read %s", argv[i]);
 			}
+			message = 1;
 			continue;
 		}
 		if (!strcmp(arg, "-u")) {
