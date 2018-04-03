	/* Only loads from .gitmodules, no overlay with .git/config */
	gitmodules_config();

	sub = submodule_from_path(null_sha1, path);

	if (prefix) {
		strbuf_addf(&sb, "%s%s", prefix, path);
		displaypath = strbuf_detach(&sb, NULL);
	} else
		displaypath = xstrdup(sub->path);

	/*
	 * Copy url setting when it is not set yet.
