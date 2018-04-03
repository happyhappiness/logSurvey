 			seen = find_used_pathspec(pathspec);
 		for (i = 0; pathspec[i]; i++) {
 			if (!seen[i] && pathspec[i][0]
-			    && !file_exists(pathspec[i]))
-				die("pathspec '%s' did not match any files",
-				    pathspec[i]);
+			    && !file_exists(pathspec[i])) {
+				if (ignore_missing) {
+					if (excluded(&dir, pathspec[i], DT_UNKNOWN))
+						dir_add_ignored(&dir, pathspec[i], strlen(pathspec[i]));
+				} else
+					die("pathspec '%s' did not match any files",
+					    pathspec[i]);
+			}
 		}
 		free(seen);
 	}
