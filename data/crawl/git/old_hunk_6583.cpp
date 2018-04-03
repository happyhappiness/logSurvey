		die(msg, path, "");
	}

	/* Successful unlink is good.. */
	if (!unlink(path))
		return 0;
