	struct stat st;
	struct child_process cp;
	int counter = 0, len, ret;

	if (!new->commit)
		die(_("no branch specified"));
