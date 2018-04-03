	strbuf_release(&key);

	if (flag & BRANCH_CONFIG_VERBOSE) {
		if (remote_is_branch) {
			if (origin)
				printf_ln(rebasing ?
					  _("Branch %s set up to track remote branch %s from %s by rebasing.") :
					  _("Branch %s set up to track remote branch %s from %s."),
					  local, shortname, origin);
			else
				printf_ln(rebasing ?
					  _("Branch %s set up to track local branch %s by rebasing.") :
					  _("Branch %s set up to track local branch %s."),
					  local, shortname);
		} else {
			if (origin)
				printf_ln(rebasing ?
					  _("Branch %s set up to track remote ref %s by rebasing.") :
					  _("Branch %s set up to track remote ref %s."),
					  local, remote);
			else
				printf_ln(rebasing ?
					  _("Branch %s set up to track local ref %s by rebasing.") :
					  _("Branch %s set up to track local ref %s."),
					  local, remote);
		}
	}
}
