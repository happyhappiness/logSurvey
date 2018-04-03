			continue;
		if (line[i] != '\t')
			break;
		if ((ws_rule & WS_SPACE_BEFORE_TAB) && written < i)
			result |= WS_SPACE_BEFORE_TAB;
		written = i + 1;
	}

	/* Check for indent using non-tab. */
	if ((ws_rule & WS_INDENT_WITH_NON_TAB) && i - written >= 8)
		result |= WS_INDENT_WITH_NON_TAB;

	if (stream) {
		/* Highlight errors in leading whitespace. */
		if ((result & WS_SPACE_BEFORE_TAB) ||
		    (result & WS_INDENT_WITH_NON_TAB)) {
			fputs(ws, stream);
			fwrite(line, written, 1, stream);
			fputs(reset, stream);
		}

		/* Now the rest of the line starts at written.
		 * The non-highlighted part ends at trailing_whitespace. */
		if (trailing_whitespace == -1)