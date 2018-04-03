	if (!*outbuf)
		die("unable to read files to diff");

	if (driver->textconv_cache && df->oid_valid) {
		/* ignore errors, as we might be in a readonly repository */
		notes_cache_put(driver->textconv_cache, df->oid.hash, *outbuf,
				size);
		/*
		 * we could save up changes and flush them all at the end,
