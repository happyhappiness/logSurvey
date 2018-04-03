	} else if (new_upstream) {
		struct branch *branch = branch_get(argv[0]);

		if (!ref_exists(branch->refname))
			die(_("branch '%s' does not exist"), branch->name);

