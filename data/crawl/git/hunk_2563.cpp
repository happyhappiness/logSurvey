 	 * it up.
 	 */
 	if (!best_strategy) {
-		restore_state(head_commit->object.sha1, stash);
+		restore_state(get_object_hash(head_commit->object), stash);
 		if (use_strategies_nr > 1)
 			fprintf(stderr,
 				_("No merge strategy handled the merge.\n"));
