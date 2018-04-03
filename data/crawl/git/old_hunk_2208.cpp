		usage(index_pack_usage);
	if (fix_thin_pack && !from_stdin)
		die(_("--fix-thin cannot be used without --stdin"));
	if (!index_name && pack_name) {
		size_t len;
		if (!strip_suffix(pack_name, ".pack", &len))
			die(_("packfile name '%s' does not end with '.pack'"),
			    pack_name);
		strbuf_add(&index_name_buf, pack_name, len);
		strbuf_addstr(&index_name_buf, ".idx");
		index_name = index_name_buf.buf;
	}
	if (keep_msg && !keep_name && pack_name) {
		size_t len;
		if (!strip_suffix(pack_name, ".pack", &len))
			die(_("packfile name '%s' does not end with '.pack'"),
			    pack_name);
		strbuf_add(&keep_name_buf, pack_name, len);
		strbuf_addstr(&keep_name_buf, ".keep");
		keep_name = keep_name_buf.buf;
	}
	if (verify) {
		if (!index_name)
			die(_("--verify with no packfile name given"));