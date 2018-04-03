			(mode & 0111) ? ((mode) << 16) : 0;
		if (S_ISREG(mode) && zlib_compression_level != 0)
			method = 8;
		result = 0;
		buffer = sha1_file_to_archive(path + base_len, sha1, mode,
				&type, &size, commit);
		if (!buffer)
			die("cannot read %s", sha1_to_hex(sha1));
		crc = crc32(crc, buffer, size);
		out = buffer;
		uncompressed_size = size;
		compressed_size = size;
	} else {
		error("unsupported file mode: 0%o (SHA1: %s)", mode,
		      sha1_to_hex(sha1));
		goto out;
	}

	if (method == 8) {
