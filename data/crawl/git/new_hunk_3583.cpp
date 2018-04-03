	default:
		die("internal error: ce_mode is %o", ce->ce_mode);
	}

	changed |= match_stat_data(&ce->ce_stat_data, st);

	/* Racily smudged entry? */
	if (!ce->ce_stat_data.sd_size) {
		if (!is_empty_blob_sha1(ce->sha1))
			changed |= DATA_CHANGED;
	}
