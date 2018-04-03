 		goto error_free_return;
 	}
 	written = write_in_full(fd, ref, len);
-	close(fd);
-	if (written != len) {
+	if (close(fd) != 0 || written != len) {
 		error("Unable to write to %s", lockpath);
 		goto error_unlink_return;
 	}