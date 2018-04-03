	rollback_lock_file(&index_lock);

	if (!clean) {
		strbuf_addstr(&msgbuf, "\nConflicts:\n\n");
		for (i = 0; i < active_nr;) {
			struct cache_entry *ce = active_cache[i++];
			if (ce_stage(ce)) {
				strbuf_addch(&msgbuf, '\t');
				strbuf_addstr(&msgbuf, ce->name);
				strbuf_addch(&msgbuf, '\n');
				while (i < active_nr && !strcmp(ce->name,
						active_cache[i]->name))
					i++;
			}
		}
		write_message(&msgbuf, defmsg);
		fprintf(stderr, "Automatic %s failed.%s\n",
			me, help_msg(commit_name));
		rerere(allow_rerere_auto);
		exit(1);
	}
	write_message(&msgbuf, defmsg);
	fprintf(stderr, "Finished one %s.\n", me);

	/*