	if (state->message_id)
		argv_array_push(&cp.args, "-m");

	argv_array_push(&cp.args, am_path(state, "msg"));
	argv_array_push(&cp.args, am_path(state, "patch"));

