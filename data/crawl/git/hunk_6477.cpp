 			    (commit->date < revs->max_age))
 				continue;
 			if (add_parents_to_list(revs, commit, &revs->commits) < 0)
-				return NULL;
+				die("Failed to traverse parents of commit %s",
+				    sha1_to_hex(commit->object.sha1));
 		}
 
 		switch (simplify_commit(revs, commit)) {
 		case commit_ignore:
 			continue;
 		case commit_error:
-			return NULL;
+			die("Failed to simplify parents of commit %s",
+			    sha1_to_hex(commit->object.sha1));
 		default:
 			return commit;
 		}
