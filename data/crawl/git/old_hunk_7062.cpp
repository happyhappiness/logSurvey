	struct pack_revindex *rix;
	struct revindex_entry *revindex;

	num = pack_revindex_ix(p);
	if (num < 0)
		die("internal error: pack revindex uninitialized");

	rix = &pack_revindex[num];
	if (!rix->revindex)
