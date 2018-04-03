		;
	}

	return len;
}

/* Return the position of the end of the trailers. */
static int find_trailer_end(const char *buf, size_t len)
{
	return len - ignore_non_trailer(buf, len);
}

static int ends_with_blank_line(const char *buf, size_t len)
{
	int ll = last_line(buf, len);
	if (ll < 0)
		return 0;
	return is_blank_line(buf + ll);
}

static int process_input_file(FILE *outfile,
			      const char *str,
			      struct list_head *head)
{
	int patch_start, trailer_start, trailer_end;
	struct strbuf tok = STRBUF_INIT;
	struct strbuf val = STRBUF_INIT;
	struct trailer_item *last = NULL;
	struct strbuf *trailer, **trailer_lines, **ptr;

	patch_start = find_patch_start(str);
	trailer_end = find_trailer_end(str, patch_start);
	trailer_start = find_trailer_start(str, trailer_end);

	/* Print lines before the trailers as is */
	fwrite(str, 1, trailer_start, outfile);

	if (!ends_with_blank_line(str, trailer_start))
		fprintf(outfile, "\n");

	/* Parse trailer lines */
	trailer_lines = strbuf_split_buf(str + trailer_start,
					 trailer_end - trailer_start,
					 '\n',
					 0);
	for (ptr = trailer_lines; *ptr; ptr++) {
		int separator_pos;
		trailer = *ptr;
		if (trailer->buf[0] == comment_line_char)
			continue;
		if (last && isspace(trailer->buf[0])) {
			struct strbuf sb = STRBUF_INIT;
			strbuf_addf(&sb, "%s\n%s", last->value, trailer->buf);
			strbuf_strip_suffix(&sb, "\n");
			free(last->value);
			last->value = strbuf_detach(&sb, NULL);
			continue;
		}
		separator_pos = find_separator(trailer->buf, separators);
		if (separator_pos >= 1) {
			parse_trailer(&tok, &val, NULL, trailer->buf,
				      separator_pos);
			last = add_trailer_item(head,
						strbuf_detach(&tok, NULL),
						strbuf_detach(&val, NULL));
		} else {
			strbuf_addbuf(&val, trailer);
			strbuf_strip_suffix(&val, "\n");
			add_trailer_item(head,
					 NULL,
					 strbuf_detach(&val, NULL));
			last = NULL;
		}
	}
	strbuf_list_free(trailer_lines);

	return trailer_end;
}
