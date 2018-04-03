 			continue;
 		}
 		if (ce_match_stat(ce, &st, 0))
-			errs = error("'%s' has local modifications "
-				     "(hint: try -f)", ce->name);
+			local_changes = 1;
 		if (no_head
 		     || get_tree_entry(head, name, sha1, &mode)
 		     || ce->ce_mode != create_ce_mode(mode)
 		     || hashcmp(ce->sha1, sha1))
-			errs = error("'%s' has changes staged in the index "
-				     "(hint: try -f)", name);
+			staged_changes = 1;
+
+		if (local_changes && staged_changes)
+			errs = error("'%s' has staged content different "
+				     "from both the file and the HEAD\n"
+				     "(use -f to force removal)", name);
+		else if (!index_only) {
+			/* It's not dangerous to git-rm --cached a
+			 * file if the index matches the file or the
+			 * HEAD, since it means the deleted content is
+			 * still available somewhere.
+			 */
+			if (staged_changes)
+				errs = error("'%s' has changes staged in the index\n"
+					     "(use --cached to keep the file, "
+					     "or -f to force removal)", name);
+			if (local_changes)
+				errs = error("'%s' has local modifications\n"
+					     "(use --cached to keep the file, "
+					     "or -f to force removal)", name);
+		}
 	}
 	return errs;
 }
