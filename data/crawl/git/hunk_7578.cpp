 		die("failed to write ref-pack file");
 	if (fflush(cbdata.refs_file) || fsync(fd) || fclose(cbdata.refs_file))
 		die("failed to write ref-pack file (%s)", strerror(errno));
+	/*
+	 * Since the lock file was fdopen()'ed and then fclose()'ed above,
+	 * assign -1 to the lock file descriptor so that commit_lock_file()
+	 * won't try to close() it.
+	 */
+	packed.fd = -1;
 	if (commit_lock_file(&packed) < 0)
 		die("unable to overwrite old ref-pack file (%s)", strerror(errno));
 	if (cbdata.flags & PACK_REFS_PRUNE)
