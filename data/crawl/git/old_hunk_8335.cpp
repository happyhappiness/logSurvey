				squelched == 1 ? "" : "s");
		}
		if (new_whitespace == error_on_whitespace)
			die("%d line%s add%s trailing whitespaces.",
			    whitespace_error,
			    whitespace_error == 1 ? "" : "s",
			    whitespace_error == 1 ? "s" : "");
		if (applied_after_stripping)
			fprintf(stderr, "warning: %d line%s applied after"
				" stripping trailing whitespaces.\n",
				applied_after_stripping,
				applied_after_stripping == 1 ? "" : "s");
		else if (whitespace_error)
			fprintf(stderr, "warning: %d line%s add%s trailing"
				" whitespaces.\n",
				whitespace_error,
				whitespace_error == 1 ? "" : "s",
				whitespace_error == 1 ? "s" : "");