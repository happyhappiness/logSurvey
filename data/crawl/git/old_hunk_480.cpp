
	if (unmerged_cache()) {
		printf_ln(_("You still have unmerged paths in your index.\n"
			"Did you forget to use 'git add'?"));
		die_user_resolve(state);
	}

