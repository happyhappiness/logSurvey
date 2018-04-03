				   squelched),
				squelched);
		}
		if (state->ws_error_action == die_on_ws_error)
			die(Q_("%d line adds whitespace errors.",
			       "%d lines add whitespace errors.",
			       state->whitespace_error),
			    state->whitespace_error);
		if (state->applied_after_fixing_ws && state->apply)
			warning("%d line%s applied after"
				" fixing whitespace errors.",
