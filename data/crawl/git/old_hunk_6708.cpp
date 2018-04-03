		}
		fclose(fp);
		strbuf_release(&m);
	} else {
		reflog_msg = "commit";
		pptr = &commit_list_insert(lookup_commit(head_sha1), pptr)->next;
	}
	parents = reduce_heads(parents);

	/* Finally, get the commit message */
	strbuf_init(&sb, 0);
	if (strbuf_read_file(&sb, git_path(commit_editmsg), 0) < 0) {
		rollback_index_files();
		die("could not read commit message");
