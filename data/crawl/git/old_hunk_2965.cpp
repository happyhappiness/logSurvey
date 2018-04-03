			write_commit_msg(state);
		}

		printf_ln(_("Applying: %.*s"), linelen(state->msg), state->msg);

		if (run_apply(state) < 0) {
			int advice_amworkdir = 1;
