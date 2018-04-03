	git_SHA1_Init(&new_sha1_ctx);

	if (lseek(pack_fd, 0, SEEK_SET) != 0)
		die("Failed seeking to start of %s: %s", pack_name, strerror(errno));
	if (read_in_full(pack_fd, &hdr, sizeof(hdr)) != sizeof(hdr))
		die("Unable to reread header of %s: %s", pack_name, strerror(errno));
	if (lseek(pack_fd, 0, SEEK_SET) != 0)
		die("Failed seeking to start of %s: %s", pack_name, strerror(errno));
	git_SHA1_Update(&old_sha1_ctx, &hdr, sizeof(hdr));
	hdr.hdr_entries = htonl(object_count);
	git_SHA1_Update(&new_sha1_ctx, &hdr, sizeof(hdr));
