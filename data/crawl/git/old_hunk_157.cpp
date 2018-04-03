	diff_setup_done(&rev.diffopt);

	head = resolve_ref_unsafe("HEAD", 0, junk_oid.hash, NULL);
	if (!strcmp(head, "HEAD"))
		head = _("detached HEAD");
	else