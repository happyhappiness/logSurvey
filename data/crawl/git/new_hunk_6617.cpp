			note);

		if (ref)
			rc |= update_local_ref(ref, what, note);
		else
			sprintf(note, "* %-*s %-*s -> FETCH_HEAD",
				SUMMARY_WIDTH, *kind ? kind : "branch",
				 REFCOL_WIDTH, *what ? what : "HEAD");
		if (*note) {
			if (verbosity >= 0 && !shown_url) {
				fprintf(stderr, "From %.*s\n",
						url_len, url);
				shown_url = 1;
			}
			if (verbosity >= 0)
				fprintf(stderr, " %s\n", note);
		}
	}
	fclose(fp);
