 	}
 	if (finish_command(&rls))
 		return error ("pack-objects died");
+	close(bundle_fd);
+	if (!bundle_to_stdout)
+		commit_lock_file(&lock);
 	return 0;
 }
 