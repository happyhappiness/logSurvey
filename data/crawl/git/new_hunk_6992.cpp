			(mode & 0111) ? ((mode) << 16) : 0;
		if (S_ISREG(mode) && zlib_compression_level != 0)
			method = 8;
		crc = crc32(crc, buffer, size);
		out = buffer;
		uncompressed_size = size;
		compressed_size = size;
	} else {
		return error("unsupported file mode: 0%o (SHA1: %s)", mode,
				sha1_to_hex(sha1));
	}

	if (method == 8) {
