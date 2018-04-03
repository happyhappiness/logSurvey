			die("could not parse HEAD commit");

		for (c = commit->parents; c; c = c->next)
			add_parent(&sb, c->item->object.sha1);
	} else if (in_merge) {
		struct strbuf m;
		FILE *fp;

		reflog_msg = "commit (merge)";
		add_parent(&sb, head_sha1);
		strbuf_init(&m, 0);
		fp = fopen(git_path("MERGE_HEAD"), "r");
		if (fp == NULL)
