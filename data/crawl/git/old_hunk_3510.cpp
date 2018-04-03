			continue;
		}

		o = deref_tag(parse_object(sha1), *argv, 0);
		if (!o || o->type != OBJ_COMMIT) {
			fprintf(stderr, "Could not get commit for %s. Skipping.\n",
					*argv);
			continue;
		}

		commit = (struct commit *)o;
		if (cutoff > commit->date)
			cutoff = commit->date;
		add_object_array((struct object *)commit, *argv, &revs);
	}

	if (cutoff)
