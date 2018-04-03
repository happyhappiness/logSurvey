 	close(rls.in);
 	if (finish_command(&rls))
 		return error ("pack-objects died");
-	if (!bundle_to_stdout)
-		commit_lock_file(&lock);
+	if (!bundle_to_stdout) {
+		if (commit_lock_file(&lock))
+			die_errno("cannot create '%s'", path);
+	}
 	return 0;
 }
 
