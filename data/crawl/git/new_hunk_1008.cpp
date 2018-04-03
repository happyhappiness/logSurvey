
	if (!stat(dir, &st)) {
		if (st.st_mode & 077)
			die(_(permissions_advice), dir);
	} else {
		/*
		 * We must be sure to create the directory with the correct mode,