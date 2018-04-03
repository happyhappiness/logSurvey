		else
			private = xstrdup(name);
		if (private) {
			if (read_ref(private, posn->old_oid.hash) < 0)
				die("Could not read ref %s", private);
			free(private);
		}
