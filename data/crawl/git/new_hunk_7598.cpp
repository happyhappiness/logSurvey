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
			die("could not open %s for reading: %s",
			    git_path("MERGE_HEAD"), strerror(errno));
		while (strbuf_getline(&m, fp, '\n') != EOF) {
			unsigned char sha1[20];
			if (get_sha1_hex(m.buf, sha1) < 0)
				die("Corrupt MERGE_HEAD file (%s)", m.buf);
			add_parent(&sb, sha1);
		}
		fclose(fp);
		strbuf_release(&m);
	} else {