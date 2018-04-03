		return 0;
	}
	remote = make_remote(name, subkey - name);
	if (!value) {
		/* if we ever have a boolean variable, e.g. "remote.*.disabled"
		 * [remote "frotz"]
		 *      disabled
		 * is a valid way to set it to true; we get NULL in value so
		 * we need to handle it here.
		 *
		 * if (!strcmp(subkey, ".disabled")) {
		 *      val = git_config_bool(key, value);
		 *      return 0;
		 * } else
		 *
		 */
		return 0; /* ignore unknown booleans */
	}
	if (!strcmp(subkey, ".url")) {
		add_url(remote, xstrdup(value));
	} else if (!strcmp(subkey, ".push")) {
		add_push_refspec(remote, xstrdup(value));
	} else if (!strcmp(subkey, ".fetch")) {
		add_fetch_refspec(remote, xstrdup(value));
	} else if (!strcmp(subkey, ".receivepack")) {
		if (!remote->receivepack)
			remote->receivepack = xstrdup(value);
		else
			error("more than one receivepack given, using the first");
	} else if (!strcmp(subkey, ".uploadpack")) {
		if (!remote->uploadpack)
			remote->uploadpack = xstrdup(value);
		else
			error("more than one uploadpack given, using the first");
	} else if (!strcmp(subkey, ".tagopt")) {
		if (!strcmp(value, "--no-tags"))
			remote->fetch_tags = -1;
	} else if (!strcmp(subkey, ".proxy")) {
		remote->http_proxy = xstrdup(value);
	} else if (!strcmp(subkey, ".skipdefaultupdate"))
		remote->skip_default_update = 1;
	return 0;
}

