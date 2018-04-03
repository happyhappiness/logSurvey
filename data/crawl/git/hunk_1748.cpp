 			output(o, 1, _("CONFLICT (%s): There is a directory with name %s in %s. "
 			       "Adding %s as %s"),
 			       conf, path, other_branch, path, new_path);
-			update_file(o, 0, sha, mode, new_path);
+			update_file(o, 0, oid, mode, new_path);
 			if (o->call_depth)
 				remove_file_from_cache(path);
 			free(new_path);
 		} else {
 			output(o, 2, _("Adding %s"), path);
 			/* do not overwrite file if already present */
-			update_file_flags(o, sha, mode, path, 1, !a_sha);
+			update_file_flags(o, oid, mode, path, 1, !a_oid);
 		}
-	} else if (a_sha && b_sha) {
+	} else if (a_oid && b_oid) {
 		/* Case C: Added in both (check for same permissions) and */
 		/* case D: Modified in both, but differently. */
 		clean_merge = merge_content(o, path,
-					    o_sha, o_mode, a_sha, a_mode, b_sha, b_mode,
+					    o_oid, o_mode, a_oid, a_mode, b_oid, b_mode,
 					    NULL);
-	} else if (!o_sha && !a_sha && !b_sha) {
+	} else if (!o_oid && !a_oid && !b_oid) {
 		/*
 		 * this entry was deleted altogether. a_mode == 0 means
 		 * we had that path and want to actively remove it.
