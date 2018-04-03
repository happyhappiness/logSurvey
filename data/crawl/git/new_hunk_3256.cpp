		 * to forbid "git merge" into a branch yet to be born.
		 * We do the same for "git pull".
		 */
		if (squash)
			die(_("Squash commit into empty head not supported yet"));
		if (fast_forward == FF_NO)
