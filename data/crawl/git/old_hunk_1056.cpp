			goto end;
		}
		if (state->applied_after_fixing_ws && state->apply)
			warning("%d line%s applied after"
				" fixing whitespace errors.",
				state->applied_after_fixing_ws,
				state->applied_after_fixing_ws == 1 ? "" : "s");
		else if (state->whitespace_error)
			warning(Q_("%d line adds whitespace errors.",
				   "%d lines add whitespace errors.",