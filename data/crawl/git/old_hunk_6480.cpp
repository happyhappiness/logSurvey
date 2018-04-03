		char fullref[PATH_MAX];
		unsigned char sha1_from_ref[20];
		unsigned char *this_result;

		this_result = refs_found ? sha1_from_ref : sha1;
		mksnpath(fullref, sizeof(fullref), *p, len, str);
		r = resolve_ref(fullref, this_result, 1, NULL);
		if (r) {
			if (!refs_found++)
				*ref = xstrdup(r);
			if (!warn_ambiguous_refs)
				break;
		}
	}
	free(last_branch);
	return refs_found;
