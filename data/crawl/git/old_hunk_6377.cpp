		return error("--all and --mirror are incompatible");
	}

	if (!refspec
		&& !(flags & TRANSPORT_PUSH_ALL)
		&& remote->push_refspec_nr) {
		refspec = remote->push_refspec;
		refspec_nr = remote->push_refspec_nr;
	}
	errs = 0;
	for (i = 0; i < remote->url_nr; i++) {
