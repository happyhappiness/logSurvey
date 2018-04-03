	if (!oldname)
		die("cannot rename the current branch while not on any.");

	if (strbuf_check_branch_ref(&oldref, oldname))
		die("Invalid branch name: '%s'", oldname);

	if (strbuf_check_branch_ref(&newref, newname))
		die("Invalid branch name: '%s'", newname);

	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
