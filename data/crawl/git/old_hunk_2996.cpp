		else
			private = xstrdup(name);
		if (private) {
			read_ref(private, posn->old_sha1);
			free(private);
		}
	}
