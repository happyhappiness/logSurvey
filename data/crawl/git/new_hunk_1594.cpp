	/* A filemode value was given: 0xxx */

	if ((i & 0600) != 0600)
		die(_("Problem with core.sharedRepository filemode value "
		    "(0%.3o).\nThe owner of files must always have "
		    "read and write permissions."), i);

	/*
	 * Mask filemode value. Others can not get write permission.