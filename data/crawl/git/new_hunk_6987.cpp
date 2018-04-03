	if (!*ar)
		die("Unknown archive format '%s'", format);

	if (compression_level != -1) {
		if ((*ar)->flags & USES_ZLIB_COMPRESSION)
			zlib_compression_level = compression_level;
		else {
			die("Argument not supported for format '%s': -%d",
					format, compression_level);
		}
	}
	args->verbose = verbose;
	args->base = base;