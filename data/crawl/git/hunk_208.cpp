 	}
 
 	if (state->update_index) {
-		res = write_locked_index(&the_index, state->lock_file, COMMIT_LOCK);
+		res = write_locked_index(&the_index, &state->lock_file, COMMIT_LOCK);
 		if (res) {
 			error(_("Unable to write new index file"));
 			res = -128;
