	for (i = 0; i < l->nr; i++) {
		struct string_list_item *it;
		it = &(l->items[i]);
		status_printf(s, color(WT_STATUS_HEADER, s), "\t");
		status_printf_more(s, color(WT_STATUS_UNTRACKED, s),
			"%s\n", quote_path(it->string, strlen(it->string),
					    &buf, s->prefix));
	}
	strbuf_release(&buf);
