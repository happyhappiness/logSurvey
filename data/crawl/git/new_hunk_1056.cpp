			goto end;
		}
		if (state->applied_after_fixing_ws && state->apply)
			warning(Q_("%d line applied after"
				   " fixing whitespace errors.",
				   "%d lines applied after"
				   " fixing whitespace errors.",
				   state->applied_after_fixing_ws),
				state->applied_after_fixing_ws);
		else if (state->whitespace_error)
			warning(Q_("%d line adds whitespace errors.",
				   "%d lines add whitespace errors.",