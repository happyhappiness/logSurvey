	struct strbuf oldref = STRBUF_INIT, newref = STRBUF_INIT, logmsg = STRBUF_INIT;
	unsigned char sha1[20];
	struct strbuf oldsection = STRBUF_INIT, newsection = STRBUF_INIT;

	if (!oldname)
		die("cannot rename the current branch while not on any.");

	strbuf_addf(&oldref, "refs/heads/%s", oldname);

	if (check_ref_format(oldref.buf))
		die("Invalid branch name: %s", oldref.buf);

	strbuf_addf(&newref, "refs/heads/%s", newname);

	if (check_ref_format(newref.buf))
		die("Invalid branch name: %s", newref.buf);

	if (resolve_ref(newref.buf, sha1, 1, NULL) && !force)
		die("A branch named '%s' already exists.", newname);

	strbuf_addf(&logmsg, "Branch: renamed %s to %s",
		 oldref.buf, newref.buf);
