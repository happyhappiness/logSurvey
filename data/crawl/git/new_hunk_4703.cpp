
		if (get_sha1_mb(arg, rev)) {
			if (has_dash_dash)          /* case (1) */
				die(_("invalid reference: %s"), arg);
			if (!patch_mode &&
			    dwim_new_local_branch &&
			    opts.track == BRANCH_TRACK_UNSPECIFIED &&
