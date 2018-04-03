		strbuf_release(&sb);

		*refs = get_submodule_ref_store(gitdir);
	} else
		die("unknown backend %s", argv[0]);

