	strbuf_release(&key);

	if (flag & BRANCH_CONFIG_VERBOSE) {
		if (shortname && origin)
			printf_ln(rebasing ?
				  _("Branch %s set up to track remote branch %s from %s by rebasing.") :
				  _("Branch %s set up to track remote branch %s from %s."),
				  local, shortname, origin);
		else if (shortname && !origin)
			printf_ln(rebasing ?
				  _("Branch %s set up to track local branch %s by rebasing.") :
				  _("Branch %s set up to track local branch %s."),
				  local, shortname);
		else if (!shortname && origin)
			printf_ln(rebasing ?
				  _("Branch %s set up to track remote ref %s by rebasing.") :
				  _("Branch %s set up to track remote ref %s."),
				  local, remote);
		else if (!shortname && !origin)
			printf_ln(rebasing ?
				  _("Branch %s set up to track local ref %s by rebasing.") :
				  _("Branch %s set up to track local ref %s."),
				  local, remote);
		else
			die("BUG: impossible combination of %p and %p",
			    shortname, origin);
	}
}
