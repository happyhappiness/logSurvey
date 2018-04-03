	default:
		die("internal error: ce_mode is %o", ce->ce_mode);
	}
	if (ce->ce_mtime != (unsigned int) st->st_mtime)
		changed |= MTIME_CHANGED;
	if (trust_ctime && ce->ce_ctime != (unsigned int) st->st_ctime)
		changed |= CTIME_CHANGED;

	if (ce->ce_uid != (unsigned int) st->st_uid ||
	    ce->ce_gid != (unsigned int) st->st_gid)
		changed |= OWNER_CHANGED;
