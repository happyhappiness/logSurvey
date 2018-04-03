		arg = "@{-1}";

	if (get_sha1_mb(arg, rev)) {
		if (has_dash_dash)          /* case (1) */
			die(_("invalid reference: %s"), arg);
		if (dwim_new_local_branch_ok &&
		    !check_filename(NULL, arg) &&
		    argc == 1) {
			const char *remote = unique_tracking_name(arg, rev);
			if (!remote)
				return argcount;
			*new_branch = arg;
			arg = remote;
			/* DWIMmed to create local branch */
		} else {
			return argcount;
		}
	}
