		pptr = &commit_list_insert(lookup_commit(head_sha1), pptr)->next;
		fp = fopen(git_path("MERGE_HEAD"), "r");
		if (fp == NULL)
			die_errno("could not open '%s' for reading",
				  git_path("MERGE_HEAD"));
		while (strbuf_getline(&m, fp, '\n') != EOF) {
			unsigned char sha1[20];
			if (get_sha1_hex(m.buf, sha1) < 0)
				die("Corrupt MERGE_HEAD file (%s)", m.buf);
			pptr = &commit_list_insert(lookup_commit(sha1), pptr)->next;
		}
		fclose(fp);
		strbuf_release(&m);
		if (!stat(git_path("MERGE_MODE"), &statbuf)) {
			if (strbuf_read_file(&sb, git_path("MERGE_MODE"), 0) < 0)
				die_errno("could not read MERGE_MODE");
			if (!strcmp(sb.buf, "no-ff"))
				allow_fast_forward = 0;
		}
