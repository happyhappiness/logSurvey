	int at, reflog_len;

	if (len == 40 && !get_sha1_hex(str, sha1)) {
		refs_found = dwim_ref(str, len, tmp_sha1, &real_ref);
		if (refs_found > 0 && warn_ambiguous_refs) {
			warning(warn_msg, len, str);
			if (advice_object_name_warning)
				fprintf(stderr, "%s\n", _(object_name_msg));
		}
		free(real_ref);
		return 0;
	}
