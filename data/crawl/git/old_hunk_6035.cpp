						    kind);
			note_len += sprintf(note + note_len, "'%s' of ", what);
		}
		note_len += sprintf(note + note_len, "%.*s", url_len, url);
		fprintf(fp, "%s\t%s\t%s\n",
			sha1_to_hex(commit ? commit->object.sha1 :
				    rm->old_sha1),
			rm->merge ? "" : "not-for-merge",
			note);

		if (ref)
			rc |= update_local_ref(ref, what, note);