	    && !origin) {
		warning(_("Not setting branch %s as its own upstream."),
			local);
		return 0;
	}

	strbuf_addf(&key, "branch.%s.remote", local);
	if (git_config_set(key.buf, origin ? origin : ".") < 0)
		goto out_err;

	strbuf_reset(&key);
	strbuf_addf(&key, "branch.%s.merge", local);
	if (git_config_set(key.buf, remote) < 0)
		goto out_err;

	if (rebasing) {
		strbuf_reset(&key);
		strbuf_addf(&key, "branch.%s.rebase", local);
		if (git_config_set(key.buf, "true") < 0)
			goto out_err;
	}
	strbuf_release(&key);

