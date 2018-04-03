 	struct child_process rls;
 	FILE *rls_fout;
 
-	/*
-	 * NEEDSWORK: this should use something like lock-file
-	 * to create temporary that is cleaned up upon error.
-	 */
-	bundle_fd = (!strcmp(path, "-") ? 1 :
-			open(path, O_CREAT | O_EXCL | O_WRONLY, 0666));
-	if (bundle_fd < 0)
-		return error("Could not create '%s': %s", path, strerror(errno));
+	bundle_to_stdout = !strcmp(path, "-");
+	if (bundle_to_stdout)
+		bundle_fd = 1;
+	else
+		bundle_fd = hold_lock_file_for_update(&lock, path, 1);
 
 	/* write signature */
 	write_or_die(bundle_fd, bundle_signature, strlen(bundle_signature));
