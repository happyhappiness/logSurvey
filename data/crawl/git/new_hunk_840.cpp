	/* Only loads from .gitmodules, no overlay with .git/config */
	gitmodules_config();

	if (prefix && get_super_prefix())
		die("BUG: cannot have prefix and superprefix");
	else if (prefix)
		displaypath = xstrdup(relative_path(path, prefix, &sb));
	else if (get_super_prefix()) {
		strbuf_addf(&sb, "%s%s", get_super_prefix(), path);
		displaypath = strbuf_detach(&sb, NULL);
	} else
		displaypath = xstrdup(path);
