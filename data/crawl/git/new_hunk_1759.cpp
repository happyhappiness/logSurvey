		die("BUG: fill_textconv called with non-textconv driver");

	if (driver->textconv_cache && df->sha1_valid) {
		*outbuf = notes_cache_get(driver->textconv_cache,
					  df->oid.hash,
					  &size);
		if (*outbuf)
			return size;
