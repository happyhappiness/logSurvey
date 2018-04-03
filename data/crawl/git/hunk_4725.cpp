 		      pathspec, seen, "Unstaged changes after refreshing the index:");
 	for (i = 0; i < specs; i++) {
 		if (!seen[i])
-			die("pathspec '%s' did not match any files", pathspec[i]);
+			die(_("pathspec '%s' did not match any files"), pathspec[i]);
 	}
         free(seen);
 }
