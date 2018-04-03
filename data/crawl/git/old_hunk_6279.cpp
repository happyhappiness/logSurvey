		create_symref("HEAD", new->path, msg.buf);
		if (!opts->quiet) {
			if (old->path && !strcmp(new->path, old->path))
				fprintf(stderr, "Already on \"%s\"\n",
					new->name);
			else
				fprintf(stderr, "Switched to%s branch \"%s\"\n",
					opts->new_branch ? " a new" : "",
					new->name);
		}
