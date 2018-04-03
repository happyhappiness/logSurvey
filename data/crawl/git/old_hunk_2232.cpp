		}
	} else if (new->path) {	/* Switch branches. */
		if (create_symref("HEAD", new->path, msg.buf) < 0)
			die("unable to update HEAD");
		if (!opts->quiet) {
			if (old->path && !strcmp(new->path, old->path)) {
				if (opts->new_branch_force)