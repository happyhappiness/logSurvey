		return checkout_paths(source_tree, pathspec);
	}

	if (opts.new_branch) {
		struct strbuf buf;
		strbuf_init(&buf, 0);
		strbuf_addstr(&buf, "refs/heads/");
		strbuf_addstr(&buf, opts.new_branch);
		if (!get_sha1(buf.buf, rev))
			die("git checkout: branch %s already exists", opts.new_branch);
		if (check_ref_format(buf.buf))
			die("git checkout: we do not like '%s' as a branch name.", opts.new_branch);
		strbuf_release(&buf);
	}

	if (new.name && !new.commit) {
		die("Cannot switch branch to a non-commit.");
	}
