
	dir = directory;

	if (avoid_alias(dir)) {
		logerror("'%s': aliased", dir);
		return NULL;
	}
