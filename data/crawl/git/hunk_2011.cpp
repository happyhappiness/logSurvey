 	if (!rc || errno == ENOENT)
 		return 0;
 	err = errno;
-	warning("unable to %s %s: %s", op, file, strerror(errno));
+	warning_errno("unable to %s %s", op, file);
 	errno = err;
 	return rc;
 }
