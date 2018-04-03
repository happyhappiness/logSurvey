				printf_ln(_("The copy of the patch that failed is found in: %s"),
						am_path(state, "patch"));

			die_user_resolve(state);
		}

		do_commit(state);
