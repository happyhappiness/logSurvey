 
 		error("failed to push some refs to '%s'", url[i]);
 		if (nonfastforward) {
-			printf("To prevent you from losing history, non-fast-forward updates were rejected.\n"
-			       "Merge the remote changes before pushing again.\n"
-			       "See the 'non-fast forward' section of 'git push --help' for details.\n");
+			printf("To prevent you from losing history, non-fast-forward updates were rejected\n"
+			       "Merge the remote changes before pushing again.  See the 'non-fast forward'\n"
+			       "section of 'git push --help' for details.\n");
 		}
 		errs++;
 	}