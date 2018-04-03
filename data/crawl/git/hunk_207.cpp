 	}
 	if (state->check_index)
 		state->unsafe_paths = 0;
-	if (!state->lock_file)
-		return error("BUG: state->lock_file should not be NULL");
 
 	if (state->apply_verbosity <= verbosity_silent) {
 		state->saved_error_routine = get_error_routine();
