		else
			private = xstrdup(name);
		if (private) {
			if (read_ref(private, posn->old_sha1) < 0)
				die("Could not read ref %s", private);
			free(private);
		}
	}
