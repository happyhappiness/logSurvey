		const char *s;

		if (!skip_prefix(buf, "Subproject commit ", &s) ||
		    get_sha1_hex(s, ce->oid.hash))
			die(_("corrupt patch for submodule %s"), path);
	} else {
		if (!state->cached) {
