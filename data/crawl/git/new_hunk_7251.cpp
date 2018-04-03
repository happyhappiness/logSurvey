	if (!remote)
		die("bad repository '%s'", repo);

	if (remote->mirror)
		flags |= (TRANSPORT_PUSH_MIRROR|TRANSPORT_PUSH_FORCE);

	if ((flags & (TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) && refspec)
		return -1;

	if ((flags & (TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) ==
				(TRANSPORT_PUSH_ALL|TRANSPORT_PUSH_MIRROR)) {
		return error("--all and --mirror are incompatible");
	}

	if (!refspec
		&& !(flags & TRANSPORT_PUSH_ALL)
		&& remote->push_refspec_nr) {
