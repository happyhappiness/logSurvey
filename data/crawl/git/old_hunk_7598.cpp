			die("could not parse HEAD commit");

		for (c = commit->parents; c; c = c->next)
			strbuf_addf(&sb, "parent %s\n",
				      sha1_to_hex(c->item->object.sha1));
	} else if (in_merge) {
		struct strbuf m;
		FILE *fp;

		reflog_msg = "commit (merge)";
		strbuf_addf(&sb, "parent %s\n", sha1_to_hex(head_sha1));
		strbuf_init(&m, 0);
		fp = fopen(git_path("MERGE_HEAD"), "r");
		if (fp == NULL)
			die("could not open %s for reading: %s",
			    git_path("MERGE_HEAD"), strerror(errno));
		while (strbuf_getline(&m, fp, '\n') != EOF)
			strbuf_addf(&sb, "parent %s\n", m.buf);
		fclose(fp);
		strbuf_release(&m);
	} else {