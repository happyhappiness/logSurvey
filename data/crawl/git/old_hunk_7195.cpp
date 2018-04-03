
	strbuf_release(&sb);

	if (use_editor) {
		if (in_merge)
			fprintf(fp,
				"#\n"
