			rm->merge ? "" : "not-for-merge",
			note);

		if (ref)
			update_local_ref(ref, what, verbose, note);
		else if (verbose)
			sprintf(note, "* %-*s %-*s -> FETCH_HEAD",
				SUMMARY_WIDTH, *kind ? kind : "branch",
				 REFCOL_WIDTH, *what ? what : "HEAD");
		else
			*note = '\0';
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