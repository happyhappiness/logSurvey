	struct pack_revindex *rix;
	struct revindex_entry *revindex;

	if (!pack_revindex_hashsz)
		init_pack_revindex();
	num = pack_revindex_ix(p);
	if (num < 0)
		die("internal error: pack revindex fubar");

	rix = &pack_revindex[num];
	if (!rix->revindex)
