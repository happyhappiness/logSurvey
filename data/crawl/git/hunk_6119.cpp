 		return error("Not tracking: ambiguous information for ref %s",
 				orig_ref);
 
-	sprintf(key, "branch.%s.remote", new_ref);
-	git_config_set(key, tracking.remote ?  tracking.remote : ".");
-	sprintf(key, "branch.%s.merge", new_ref);
-	git_config_set(key, tracking.src ? tracking.src : orig_ref);
-	printf("Branch %s set up to track %s branch %s.\n", new_ref,
-		tracking.remote ? "remote" : "local", orig_ref);
-	if (should_setup_rebase(&tracking)) {
-		sprintf(key, "branch.%s.rebase", new_ref);
-		git_config_set(key, "true");
-		printf("This branch will rebase on pull.\n");
-	}
-	free(tracking.src);
+	install_branch_config(BRANCH_CONFIG_VERBOSE, new_ref, tracking.remote,
+			      tracking.src ? tracking.src : orig_ref);
 
+	free(tracking.src);
 	return 0;
 }
 
