			    whitespace_error == 1 ? "" : "s",
			    whitespace_error == 1 ? "s" : "");
		if (applied_after_fixing_ws && apply)
			fprintf(stderr, "warning: %d line%s applied after"
				" fixing whitespace errors.\n",
				applied_after_fixing_ws,
				applied_after_fixing_ws == 1 ? "" : "s");
		else if (whitespace_error)
			fprintf(stderr, "warning: %d line%s add%s whitespace errors.\n",
				whitespace_error,
				whitespace_error == 1 ? "" : "s",
				whitespace_error == 1 ? "s" : "");
