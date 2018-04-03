			note);

		if (ref)
			rc |= update_local_ref(ref, what, verbose, note);
		else
			sprintf(note, "* %-*s %-*s -> FETCH_HEAD",
				SUMMARY_WIDTH, *kind ? kind : "branch",
				 REFCOL_WIDTH, *what ? what : "HEAD");
		if (*note) {
			if (!shown_url) {
				fprintf(stderr, "From %.*s\n",
						url_len, url);
				shown_url = 1;
			}
			fprintf(stderr, " %s\n", note);
		}
	}
	fclose(fp);
