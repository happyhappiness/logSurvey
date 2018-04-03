	int we_knew_they_have = 0;

	if (get_sha1_hex(hex, sha1))
		die("git upload-pack: expected SHA1 object, got '%s'", hex);
	if (!has_sha1_file(sha1))
		return -1;

