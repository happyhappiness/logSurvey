		match_end = !trailing;
	}

	lines = 0;
	pos = frag->newpos;
	for (;;) {
		offset = find_offset(buf->buf, buf->len,
				     oldlines, oldsize, pos, &lines,
				     match_beginning, match_end);
		if (offset >= 0) {
			if (ws_error_action == correct_ws_error &&
			    (buf->len - oldsize - offset == 0))
				/* end of file? */
				newsize -= new_blank_lines_at_end;

			/*
			 * Warn if it was necessary to reduce the number
			 * of context lines.
			 */
			if ((leading != frag->leading) ||
			    (trailing != frag->trailing))
				fprintf(stderr, "Context reduced to (%ld/%ld)"
					" to apply fragment at %d\n",
					leading, trailing, pos + lines);

			strbuf_splice(buf, offset, oldsize, newlines, newsize);
			offset = 0;
			break;
		}

		/* Am I at my context limits? */
		if ((leading <= p_context) && (trailing <= p_context))
