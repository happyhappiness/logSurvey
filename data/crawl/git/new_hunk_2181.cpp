	if (safe_create_leading_directories_const(path) < 0)
		die(_("could not create directory '%s'"), path);

	strbuf_addf(&sb, "%s/.git", path);

	if (safe_create_leading_directories_const(sb.buf) < 0)
		die(_("could not create leading directories of '%s'"), sb.buf);