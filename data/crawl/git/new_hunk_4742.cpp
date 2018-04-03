
	dest_exists = !stat(dir, &buf);
	if (dest_exists && !is_empty_dir(dir))
		die(_("destination path '%s' already exists and is not "
			"an empty directory."), dir);

	strbuf_addf(&reflog_msg, "clone: from %s", repo);

