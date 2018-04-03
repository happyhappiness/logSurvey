 			/* Deleted in both or deleted in one and
 			 * unchanged in the other */
 			if (a_sha)
-				output(2, "Removing %s", path);
+				output(o, 2, "Removing %s", path);
 			/* do not touch working file if it did not exist */
 			remove_file(1, path, !a_sha);
 		} else {
 			/* Deleted in one and changed in the other */
 			clean_merge = 0;
 			if (!a_sha) {
-				output(1, "CONFLICT (delete/modify): %s deleted in %s "
+				output(o, 1, "CONFLICT (delete/modify): %s deleted in %s "
 				       "and modified in %s. Version %s of %s left in tree.",
-				       path, branch1,
-				       branch2, branch2, path);
+				       path, o->branch1,
+				       o->branch2, o->branch2, path);
 				update_file(0, b_sha, b_mode, path);
 			} else {
-				output(1, "CONFLICT (delete/modify): %s deleted in %s "
+				output(o, 1, "CONFLICT (delete/modify): %s deleted in %s "
 				       "and modified in %s. Version %s of %s left in tree.",
-				       path, branch2,
-				       branch1, branch1, path);
+				       path, o->branch2,
+				       o->branch1, o->branch1, path);
 				update_file(0, a_sha, a_mode, path);
 			}
 		}
