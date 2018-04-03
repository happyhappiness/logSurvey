	struct string_list revlist_args = STRING_LIST_INIT_NODUP;
	struct strbuf buf = STRBUF_INIT;

	helper = get_helper(transport);

	write_constant(helper->in, "export\n");
