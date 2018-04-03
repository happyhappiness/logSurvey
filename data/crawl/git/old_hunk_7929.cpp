		prune = 0;
		if (!need_to_gc())
			return 0;
	} else {
		/*
		 * Use safer (for shared repos) "-A" option to