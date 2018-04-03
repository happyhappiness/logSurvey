 	safe_create_leading_directories(name);
 	return open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
 }
+
+int unlink_or_warn(const char *file)
+{
+	int rc = unlink(file);
+
+	if (rc < 0) {
+		int err = errno;
+		if (ENOENT != err) {
+			warning("unable to unlink %s: %s",
+				file, strerror(errno));
+			errno = err;
+		}
+	}
+	return rc;
+}
+