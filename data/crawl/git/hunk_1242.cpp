 		return 0;
 
 	assert(patch->is_new <= 0);
-	previous = previous_patch(patch, &status);
+	previous = previous_patch(state, patch, &status);
 
 	if (status)
 		return error(_("path %s has been renamed/deleted"), old_name);
 	if (previous) {
 		st_mode = previous->new_mode;
-	} else if (!cached) {
+	} else if (!state->cached) {
 		stat_ret = lstat(old_name, st);
 		if (stat_ret && errno != ENOENT)
 			return error(_("%s: %s"), old_name, strerror(errno));
 	}
 
-	if (check_index && !previous) {
+	if (state->check_index && !previous) {
 		int pos = cache_name_pos(old_name, strlen(old_name));
 		if (pos < 0) {
 			if (patch->is_new < 0)
