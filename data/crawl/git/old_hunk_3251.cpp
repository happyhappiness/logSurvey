		strbuf_release(&truname);
	}

	if (!strcmp(remote, "FETCH_HEAD") &&
			!access(git_path("FETCH_HEAD"), R_OK)) {
		const char *filename;
		FILE *fp;
		struct strbuf line = STRBUF_INIT;
		char *ptr;

		filename = git_path("FETCH_HEAD");
		fp = fopen(filename, "r");
		if (!fp)
			die_errno(_("could not open '%s' for reading"),
				  filename);
		strbuf_getline(&line, fp, '\n');
		fclose(fp);
		ptr = strstr(line.buf, "\tnot-for-merge\t");
		if (ptr)
			strbuf_remove(&line, ptr-line.buf+1, 13);
		strbuf_addbuf(msg, &line);
		strbuf_release(&line);
		goto cleanup;
	}

	if (remote_head->util) {
		struct merge_remote_desc *desc;
		desc = merge_remote_util(remote_head);
