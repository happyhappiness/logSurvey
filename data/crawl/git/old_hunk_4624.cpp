				 REFCOL_WIDTH, *what ? what : "HEAD");
		if (*note) {
			if (verbosity >= 0 && !shown_url) {
				fprintf(stderr, "From %.*s\n",
						url_len, url);
				shown_url = 1;
			}
