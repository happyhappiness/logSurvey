				apply = 0;
		}

		if (apply_verbosely && applied_pos != pos) {
			int offset = applied_pos - pos;
			if (apply_in_reverse)
				offset = 0 - offset;
			fprintf(stderr,
				"Hunk #%d succeeded at %d (offset %d lines).\n",
				nth_fragment, applied_pos + 1, offset);
		}

		/*
		 * Warn if it was necessary to reduce the number
		 * of context lines.
