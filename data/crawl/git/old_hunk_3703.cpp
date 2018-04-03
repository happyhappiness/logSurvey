
	if (flag & BRANCH_CONFIG_VERBOSE) {
		if (remote_is_branch && origin)
			printf(rebasing ?
			       "Branch %s set up to track remote branch %s from %s by rebasing.\n" :
			       "Branch %s set up to track remote branch %s from %s.\n",
			       local, shortname, origin);
		else if (remote_is_branch && !origin)
			printf(rebasing ?
			       "Branch %s set up to track local branch %s by rebasing.\n" :
			       "Branch %s set up to track local branch %s.\n",
			       local, shortname);
		else if (!remote_is_branch && origin)
			printf(rebasing ?
			       "Branch %s set up to track remote ref %s by rebasing.\n" :
			       "Branch %s set up to track remote ref %s.\n",
			       local, remote);
		else if (!remote_is_branch && !origin)
			printf(rebasing ?
			       "Branch %s set up to track local ref %s by rebasing.\n" :
			       "Branch %s set up to track local ref %s.\n",
			       local, remote);
		else
			die("BUG: impossible combination of %d and %p",
			    remote_is_branch, origin);
