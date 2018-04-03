			die(_("--reflog option needs one branch name"));

		if (MAX_REVS < reflog)
			die("Only %d entries can be shown at one time.",
			    MAX_REVS);
		if (!dwim_ref(*av, strlen(*av), oid.hash, &ref))
			die(_("no such ref %s"), *av);

