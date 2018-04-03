	}

	if (is_empty_file(am_path(state, "patch"))) {
		printf_ln(_("Patch is empty."));
		die_user_resolve(state);
	}

