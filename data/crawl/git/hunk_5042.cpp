 			if (old->path && !strcmp(new->path, old->path))
 				fprintf(stderr, "Already on '%s'\n",
 					new->name);
-			else
+			else if (opts->new_branch)
 				fprintf(stderr, "Switched to%s branch '%s'\n",
 					opts->branch_exists ? " and reset" : " a new",
 					new->name);
+			else
+				fprintf(stderr, "Switched to branch '%s'\n",
+					new->name);
 		}
 		if (old->path && old->name) {
 			char log_file[PATH_MAX], ref_file[PATH_MAX];