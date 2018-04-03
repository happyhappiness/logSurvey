		struct sha1file *f;
		unsigned char read_sha1[20], tail_sha1[20];
		struct strbuf msg = STRBUF_INIT;
		int nr_unresolved = nr_ofs_deltas + nr_ref_deltas - nr_resolved_deltas;
		int nr_objects_initial = nr_objects;
		if (nr_unresolved <= 0)
			die(_("confusion beyond insanity"));
