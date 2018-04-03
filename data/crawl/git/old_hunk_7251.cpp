	if (!remote)
		die("bad repository '%s'", repo);

	if (!refspec
		&& !(flags & TRANSPORT_PUSH_ALL)
		&& remote->push_refspec_nr) {
