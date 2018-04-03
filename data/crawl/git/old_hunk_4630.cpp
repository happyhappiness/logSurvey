
	err = start_command(&revlist);
	if (err) {
		error("could not run rev-list");
		return err;
	}

