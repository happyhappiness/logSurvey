	if (!be)
		die("BUG: reference backend %s is unknown", be_name);

	refs = be->init(gitdir);
	return refs;
}

