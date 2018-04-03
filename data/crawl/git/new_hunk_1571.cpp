			struct fragment dummy;
			if (parse_fragment_header(line, len, &dummy) < 0)
				continue;
			error(_("patch fragment without header at line %d: %.*s"),
				     state->linenr, (int)len-1, line);
			return -128;
		}

		if (size < len + 6)
