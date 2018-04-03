 			const char *new_path = unique_path(path, add_branch);
 			clean_merge = 0;
 			output(1, "CONFLICT (%s): There is a directory with name %s in %s. "
-			       "Added %s as %s",
+			       "Adding %s as %s",
 			       conf, path, other_branch, path, new_path);
 			remove_file(0, path, 0);
 			update_file(0, sha, mode, new_path);
 		} else {
-			output(2, "Added %s", path);
+			output(2, "Adding %s", path);
 			update_file(1, sha, mode, path);
 		}
 	} else if (a_sha && b_sha) {
