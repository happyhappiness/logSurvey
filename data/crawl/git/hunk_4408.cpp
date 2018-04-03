 		 * to work on.
 		 */
 		if (write_cache_as_tree(head, 0, NULL))
-			die ("Your index file is unmerged.");
+			die (_("Your index file is unmerged."));
 	} else {
 		if (get_sha1("HEAD", head))
-			die ("You do not have a valid HEAD");
+			die (_("You do not have a valid HEAD"));
 		if (index_differs_from("HEAD", 0))
 			die_dirty_index(me);
 	}
 	discard_cache();
 
 	if (!commit->parents) {
 		if (action == REVERT)
-			die ("Cannot revert a root commit");
+			die (_("Cannot revert a root commit"));
 		parent = NULL;
 	}
 	else if (commit->parents->next) {
