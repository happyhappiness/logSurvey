
	/* Add an arg item for each trailer on the command line */
	for_each_string_list_item(tr, trailers) {
		if (!parse_trailer(&tok, &val, &conf, tr->string))
			add_arg_item(arg_head,
				     strbuf_detach(&tok, NULL),
				     strbuf_detach(&val, NULL),
				     conf);
	}
}

static struct strbuf **read_input_file(const char *file)
