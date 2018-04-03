 		snprintf(msg, sizeof msg, "branch: Created from %s",
 			 start_name);
 
-	/* When branching off a remote branch, set up so that git-pull
-	   automatically merges from there.  So far, this is only done for
-	   remotes registered via .git/config.  */
 	if (real_ref && track)
-		setup_tracking(name, real_ref);
+		setup_tracking(name, real_ref, track);
 
 	if (write_ref_sha1(lock, sha1, msg) < 0)
 		die("Failed to write ref: %s.", strerror(errno));
 
-	if (real_ref)
-		free(real_ref);
+	free(real_ref);
 }
 
 void remove_branch_state(void)
