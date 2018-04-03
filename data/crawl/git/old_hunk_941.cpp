		;
	}

	return count;
}

/* Get the index of the end of the trailers */
static int find_trailer_end(struct strbuf **lines, int patch_start)
{
	struct strbuf sb = STRBUF_INIT;
	int i, ignore_bytes;

	for (i = 0; i < patch_start; i++)
		strbuf_addbuf(&sb, lines[i]);
	ignore_bytes = ignore_non_trailer(sb.buf, sb.len);
	strbuf_release(&sb);
	for (i = patch_start - 1; i >= 0 && ignore_bytes > 0; i--)
		ignore_bytes -= lines[i]->len;

	return i + 1;
}

static int has_blank_line_before(struct strbuf **lines, int start)
{
	for (;start >= 0; start--) {
		if (lines[start]->buf[0] == comment_line_char)
			continue;
		return contains_only_spaces(lines[start]->buf);
	}
	return 0;
}

static void print_lines(FILE *outfile, struct strbuf **lines, int start, int end)
{
	int i;
	for (i = start; lines[i] && i < end; i++)
		fprintf(outfile, "%s", lines[i]->buf);
}

static int process_input_file(FILE *outfile,
			      struct strbuf **lines,
			      struct list_head *head)
{
	int count = 0;
	int patch_start, trailer_start, trailer_end, i;
	struct strbuf tok = STRBUF_INIT;
	struct strbuf val = STRBUF_INIT;
	struct trailer_item *last = NULL;

	/* Get the line count */
	while (lines[count])
		count++;

	patch_start = find_patch_start(lines, count);
	trailer_end = find_trailer_end(lines, patch_start);
	trailer_start = find_trailer_start(lines, trailer_end);

	/* Print lines before the trailers as is */
	print_lines(outfile, lines, 0, trailer_start);

	if (!has_blank_line_before(lines, trailer_start - 1))
		fprintf(outfile, "\n");

	/* Parse trailer lines */
	for (i = trailer_start; i < trailer_end; i++) {
		int separator_pos;
		if (lines[i]->buf[0] == comment_line_char)
			continue;
		if (last && isspace(lines[i]->buf[0])) {
			struct strbuf sb = STRBUF_INIT;
			strbuf_addf(&sb, "%s\n%s", last->value, lines[i]->buf);
			strbuf_strip_suffix(&sb, "\n");
			free(last->value);
			last->value = strbuf_detach(&sb, NULL);
			continue;
		}
		separator_pos = find_separator(lines[i]->buf, separators);
		if (separator_pos >= 1) {
			parse_trailer(&tok, &val, NULL, lines[i]->buf,
				      separator_pos);
			last = add_trailer_item(head,
						strbuf_detach(&tok, NULL),
						strbuf_detach(&val, NULL));
		} else {
			strbuf_addbuf(&val, lines[i]);
			strbuf_strip_suffix(&val, "\n");
			add_trailer_item(head,
					 NULL,
					 strbuf_detach(&val, NULL));
			last = NULL;
		}
	}

	return trailer_end;
}
