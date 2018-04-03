
	argv_array_push(&cp.args, "mailinfo");
	argv_array_push(&cp.args, state->utf8 ? "-u" : "-n");

	switch (state->keep) {
	case KEEP_FALSE:
		break;
	case KEEP_TRUE:
		argv_array_push(&cp.args, "-k");
		break;
	case KEEP_NON_PATCH:
		argv_array_push(&cp.args, "-b");
		break;
	default:
		die("BUG: invalid value for state->keep");
	}

	argv_array_push(&cp.args, am_path(state, "msg"));
	argv_array_push(&cp.args, am_path(state, "patch"));

