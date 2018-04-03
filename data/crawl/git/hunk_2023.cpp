 	dir = opendir(path.buf);
 	if (!dir) {
 		if (errno != ENOENT)
-			error("unable to open object pack directory: %s: %s",
-			      path.buf, strerror(errno));
+			error_errno("unable to open object pack directory: %s",
+				    path.buf);
 		strbuf_release(&path);
 		return;
 	}
