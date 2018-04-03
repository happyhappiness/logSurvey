 	}
 	discard_cache();
 
-	index_fd = hold_locked_index(&index_lock, 1);
-
 	if (!commit->parents) {
 		if (action == REVERT)
 			die ("Cannot revert a root commit");
