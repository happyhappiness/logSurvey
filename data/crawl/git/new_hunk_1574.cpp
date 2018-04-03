		offset += nr;
	}

	if (!list && !skipped_patch) {
		error(_("unrecognized input"));
		res = -128;
		goto end;
	}

	if (state->whitespace_error && (state->ws_error_action == die_on_ws_error))
		state->apply = 0;
