				continue; /* Yup, this one exists unmerged */
		}

		if (lstat(ent->name, &st))
			die_errno("Cannot lstat '%s'", ent->name);

		if (pathspec) {
			memset(seen, 0, argc > 0 ? argc : 1);
