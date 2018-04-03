		const char *s;

		if (!skip_prefix(buf, "Subproject commit ", &s) ||
		    get_sha1_hex(s, ce->sha1))
			die(_("corrupt patch for submodule %s"), path);
	} else {
		if (!state->cached) {
			if (lstat(path, &st) < 0)
				die_errno(_("unable to stat newly created file '%s'"),
					  path);
			fill_stat_cache_info(ce, &st);
		}
		if (write_sha1_file(buf, size, blob_type, ce->sha1) < 0)
			die(_("unable to create backing store for newly created file %s"), path);
	}
	if (add_cache_entry(ce, ADD_CACHE_OK_TO_ADD) < 0)
		die(_("unable to add cache entry for %s"), path);
}

static int try_create_file(const char *path, unsigned int mode, const char *buf, unsigned long size)
