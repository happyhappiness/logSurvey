				printf_ln(_("The copy of the patch that failed is found in: %s"),
						am_path(state, "patch"));

			exit(128);
		}

		do_commit(state);
