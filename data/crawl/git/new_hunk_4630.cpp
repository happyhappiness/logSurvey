
	err = start_command(&revlist);
	if (err) {
		error(_("could not run rev-list"));
		return err;
	}

