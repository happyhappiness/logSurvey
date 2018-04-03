		strbuf_addch(out, '\n');
	else
		strbuf_addf(out, " into %s\n", current_branch);

	if (merge_summary) {
		struct commit *head;