	sb.ent = ent;
	sb.path = path;

	if (revs_file && read_ancestry(revs_file))
		die("reading graft file %s failed: %s",
		    revs_file, strerror(errno));

	read_mailmap(&mailmap, ".mailmap", NULL);

	if (!incremental)