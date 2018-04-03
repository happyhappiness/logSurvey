 
 		if (!force &&
 		    !in_merge_bases(rev, &head_rev, 1)) {
-			error("The branch '%s' is not a strict subset of "
+			error("The branch '%s' is not an ancestor of "
 				"your current HEAD.\n"
 				"If you are sure you want to delete it, "
 				"run 'git branch -D %s'.", argv[i], argv[i]);
