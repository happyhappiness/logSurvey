		    get_sha1_hex(s, ce->sha1))
			die(_("corrupt patch for submodule %s"), path);
	} else {
		if (!state->cached) {
			if (lstat(path, &st) < 0)
				die_errno(_("unable to stat newly created file '%s'"),
					  path);
