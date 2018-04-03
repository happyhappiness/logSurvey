
	write_file(am_path(state, "messageid"), 1, state->message_id ? "t" : "f");

	switch (state->scissors) {
	case SCISSORS_UNSET:
		str = "";
		break;
	case SCISSORS_FALSE:
		str = "f";
		break;
	case SCISSORS_TRUE:
		str = "t";
		break;
	default:
		die("BUG: invalid value for state->scissors");
	}

	write_file(am_path(state, "scissors"), 1, "%s", str);

	if (state->rebasing)
		write_file(am_path(state, "rebasing"), 1, "%s", "");
	else
