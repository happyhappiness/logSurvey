	sb.ent = ent;
	sb.path = path;

	read_mailmap(&mailmap, ".mailmap", NULL);

	if (!incremental)