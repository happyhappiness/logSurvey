		}
	}

	if (merge_recursive(base == NULL ?
				NULL : sha1_to_hex(base->object.sha1),
				sha1_to_hex(head), "HEAD",
				sha1_to_hex(next->object.sha1), oneline) ||
			write_cache_as_tree(head, 0, NULL)) {
		add_to_msg("\nConflicts:\n\n");
		read_cache();
		for (i = 0; i < active_nr;) {
			struct cache_entry *ce = active_cache[i++];
			if (ce_stage(ce)) {