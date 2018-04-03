
	/* Add an arg item for each trailer on the command line */
	for_each_string_list_item(tr, trailers) {
		int separator_pos = find_separator(tr->string, cl_separators);
		if (separator_pos == 0) {
			struct strbuf sb = STRBUF_INIT;
			strbuf_addstr(&sb, tr->string);
			strbuf_trim(&sb);
			error(_("empty trailer token in trailer '%.*s'"),
			      (int) sb.len, sb.buf);
			strbuf_release(&sb);
		} else {
			parse_trailer(&tok, &val, &conf, tr->string,
				      separator_pos);
			add_arg_item(arg_head,
				     strbuf_detach(&tok, NULL),
				     strbuf_detach(&val, NULL),
				     conf);
		}
	}

	free(cl_separators);
}

static struct strbuf **read_input_file(const char *file)
