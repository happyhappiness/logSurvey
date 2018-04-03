			if (parse_fragment_header(line, len, &dummy) < 0)
				continue;
			die(_("patch fragment without header at line %d: %.*s"),
			    linenr, (int)len-1, line);
		}

		if (size < len + 6)
