		arg = "@{-1}";

	if (get_sha1_mb(arg, rev)) {
		/*
		 * Either case (3) or (4), with <something> not being
		 * a commit, or an attempt to use case (1) with an
		 * invalid ref.
		 *
		 * It's likely an error, but we need to find out if
		 * we should auto-create the branch, case (3).(b).
		 */
		int recover_with_dwim = dwim_new_local_branch_ok;

		if (check_filename(NULL, arg) && !has_dash_dash)
			recover_with_dwim = 0;
		/*
		 * Accept "git checkout foo" and "git checkout foo --"
		 * as candidates for dwim.
		 */
		if (!(argc == 1 && !has_dash_dash) &&
		    !(argc == 2 && has_dash_dash))
			recover_with_dwim = 0;

		if (recover_with_dwim) {
			const char *remote = unique_tracking_name(arg, rev);
			if (remote) {
				*new_branch = arg;
				arg = remote;
				/* DWIMmed to create local branch, case (3).(b) */
			} else {
				recover_with_dwim = 0;
			}
		}

		if (!recover_with_dwim) {
			if (has_dash_dash)
				die(_("invalid reference: %s"), arg);
			return argcount;
		}
	}
