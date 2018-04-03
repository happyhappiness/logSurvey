 	}
 	if (finish_command(&rls))
 		return error ("pack-objects died");
-	close(bundle_fd);
-	if (!bundle_to_stdout)
-		commit_lock_file(&lock);
-	return 0;
+
+	return bundle_to_stdout ? close(bundle_fd) : commit_lock_file(&lock);
 }
 
 int unbundle(struct bundle_header *header, int bundle_fd)
