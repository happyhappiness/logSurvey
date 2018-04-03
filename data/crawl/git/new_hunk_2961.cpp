		printf_ln(_("No changes - did you forget to use 'git add'?\n"
			"If there is nothing left to stage, chances are that something else\n"
			"already introduced the same changes; you might want to skip this patch."));
		die_user_resolve(state);
	}

	if (unmerged_cache()) {
		printf_ln(_("You still have unmerged paths in your index.\n"
			"Did you forget to use 'git add'?"));
		die_user_resolve(state);
	}

	do_commit(state);
