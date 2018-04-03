	}

	close(po.in);
	if (finish_command(&po))
		return error("pack-objects died with strange error");
	return 0;
