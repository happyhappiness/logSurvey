			die("could not parse HEAD commit");

		for (c = commit->parents; c; c = c->next)
			pptr = &commit_list_insert(c->item, pptr)->next;
	} else if (in_merge) {
		struct strbuf m;
		FILE *fp;

		reflog_msg = "commit (merge)";
		pptr = &commit_list_insert(lookup_commit(head_sha1), pptr)->next;
		strbuf_init(&m, 0);
		fp = fopen(git_path("MERGE_HEAD"), "r");
		if (fp == NULL)
