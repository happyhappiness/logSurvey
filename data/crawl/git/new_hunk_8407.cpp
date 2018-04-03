		if (!err)
			continue;

		error("failed to push to '%s'", remote->uri[i]);
		switch (err) {
		case -ERR_RUN_COMMAND_FORK:
			error("unable to fork for %s", sender);
