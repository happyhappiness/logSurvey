		else if (ce_compare_gitlink(ce))
			changed |= DATA_CHANGED;
		return changed;
	default:
		die("internal error: ce_mode is %o", ce->ce_mode);
	}
	if (ce->ce_mtime != (unsigned int) st->st_mtime)
		changed |= MTIME_CHANGED;
	if (ce->ce_ctime != (unsigned int) st->st_ctime)
		changed |= CTIME_CHANGED;

	if (ce->ce_uid != (unsigned int) st->st_uid ||
	    ce->ce_gid != (unsigned int) st->st_gid)
		changed |= OWNER_CHANGED;
	if (ce->ce_ino != (unsigned int) st->st_ino)
		changed |= INODE_CHANGED;

#ifdef USE_STDEV
