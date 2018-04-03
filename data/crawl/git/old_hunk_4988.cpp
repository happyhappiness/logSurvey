	if (!no_verify && run_hook(index_file, "pre-commit", NULL))
		return 0;

	if (message.len) {
		strbuf_addbuf(&sb, &message);
		hook_arg1 = "message";
