		if (fd < 0)
			die_errno(_("could not create file '%s'"), path);

		if (!is_null_oid(prev)) {
			write_tag_body(fd, prev);
		} else {
			struct strbuf buf = STRBUF_INIT;
