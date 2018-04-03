			die(_("Unexpected tail checksum for %s "
			      "(disk corruption?)"), curr_pack);
	}
	if (nr_deltas != nr_resolved_deltas)
		die(Q_("pack has %d unresolved delta",
		       "pack has %d unresolved deltas",
		       nr_deltas - nr_resolved_deltas),
		    nr_deltas - nr_resolved_deltas);
}

static int write_compressed(struct sha1file *f, void *in, unsigned int size)
