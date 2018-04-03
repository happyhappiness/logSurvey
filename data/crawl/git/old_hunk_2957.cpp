
		say(state, stdout, _("Applying: %.*s"), linelen(state->msg), state->msg);

		if (run_apply(state) < 0) {
			int advice_amworkdir = 1;

			printf_ln(_("Patch failed at %s %.*s"), msgnum(state),
