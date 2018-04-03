	struct strbuf oldref = STRBUF_INIT, newref = STRBUF_INIT, logmsg = STRBUF_INIT;
	unsigned char sha1[20];
	struct strbuf oldsection = STRBUF_INIT, newsection = STRBUF_INIT;

	if (!oldname)
		die("cannot rename the current branch while not on any.");

	if (strbuf_check_branch_ref(&oldref, oldname))
		die("Invalid branch name: '%s'", oldname);

	if (strbuf_check_branch_ref(&newref, newname))
		die("Invalid branch name: '%s'", newname);
