		goto abort;
	}

	for (rm = ref_map; rm; rm = rm->next) {
		struct ref *ref = NULL;

		if (rm->peer_ref) {
			ref = xcalloc(1, sizeof(*ref) + strlen(rm->peer_ref->name) + 1);
			strcpy(ref->name, rm->peer_ref->name);
			hashcpy(ref->old_sha1, rm->peer_ref->old_sha1);
			hashcpy(ref->new_sha1, rm->old_sha1);
			ref->force = rm->peer_ref->force;
		}

		commit = lookup_commit_reference_gently(rm->old_sha1, 1);
		if (!commit)
			rm->merge = 0;

		if (!strcmp(rm->name, "HEAD")) {
			kind = "";
			what = "";
		}
		else if (!prefixcmp(rm->name, "refs/heads/")) {
			kind = "branch";
			what = rm->name + 11;
		}
		else if (!prefixcmp(rm->name, "refs/tags/")) {
			kind = "tag";
			what = rm->name + 10;
		}
		else if (!prefixcmp(rm->name, "refs/remotes/")) {
			kind = "remote-tracking branch";
			what = rm->name + 13;
		}
		else {
			kind = "";
			what = rm->name;
		}

		url_len = strlen(url);
		for (i = url_len - 1; url[i] == '/' && 0 <= i; i--)
			;
		url_len = i + 1;
		if (4 < i && !strncmp(".git", url + i - 3, 4))
			url_len = i - 3;

		strbuf_reset(&note);
		if (*what) {
			if (*kind)
				strbuf_addf(&note, "%s ", kind);
			strbuf_addf(&note, "'%s' of ", what);
		}
		fprintf(fp, "%s\t%s\t%s",
			sha1_to_hex(rm->old_sha1),
			rm->merge ? "" : "not-for-merge",
			note.buf);
		for (i = 0; i < url_len; ++i)
			if ('\n' == url[i])
				fputs("\\n", fp);
			else
				fputc(url[i], fp);
		fputc('\n', fp);

		strbuf_reset(&note);
		if (ref) {
			rc |= update_local_ref(ref, what, &note);
			free(ref);
		} else
			strbuf_addf(&note, "* %-*s %-*s -> FETCH_HEAD",
				    TRANSPORT_SUMMARY_WIDTH,
				    *kind ? kind : "branch",
				    REFCOL_WIDTH,
				    *what ? what : "HEAD");
		if (note.len) {
			if (verbosity >= 0 && !shown_url) {
				fprintf(stderr, _("From %.*s\n"),
						url_len, url);
				shown_url = 1;
			}
			if (verbosity >= 0)
				fprintf(stderr, " %s\n", note.buf);
		}
	}

