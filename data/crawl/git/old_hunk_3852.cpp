		struct branch *branch = branch_get(argv[0]);
		struct strbuf buf = STRBUF_INIT;

		if (!branch_has_merge_config(branch)) {
			die(_("Branch '%s' has no upstream information"), branch->name);
		}
