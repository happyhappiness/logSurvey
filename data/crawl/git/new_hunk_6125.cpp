		    squelch_whitespace_errors < whitespace_error) {
			int squelched =
				whitespace_error - squelch_whitespace_errors;
			warning("squelched %d "
				"whitespace error%s",
				squelched,
				squelched == 1 ? "" : "s");
		}
