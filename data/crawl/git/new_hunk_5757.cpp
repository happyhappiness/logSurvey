			entlen = pathlen - baselen;
		}
		if (mode != S_IFGITLINK && !missing_ok && !has_sha1_file(sha1))
			return error("invalid object %06o %s for '%.*s'",
				mode, sha1_to_hex(sha1), entlen+baselen, path);

		if (ce->ce_flags & CE_REMOVE)
			continue; /* entry being removed */