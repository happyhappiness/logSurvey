 			goto out;
 		ret = errno;
 	}
-	unlink(tmpfile);
+	unlink_or_warn(tmpfile);
 	if (ret) {
 		if (ret != EEXIST) {
 			return error("unable to write sha1 filename %s: %s\n", filename, strerror(ret));
