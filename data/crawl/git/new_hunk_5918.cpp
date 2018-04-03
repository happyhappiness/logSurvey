	git_SHA1_Init(&new_sha1_ctx);

	if (lseek(pack_fd, 0, SEEK_SET) != 0)
		die_errno("Failed seeking to start of '%s'", pack_name);
	if (read_in_full(pack_fd, &hdr, sizeof(hdr)) != sizeof(hdr))
		die_errno("Unable to reread header of '%s'", pack_name);
	if (lseek(pack_fd, 0, SEEK_SET) != 0)
		die_errno("Failed seeking to start of '%s'", pack_name);
	git_SHA1_Update(&old_sha1_ctx, &hdr, sizeof(hdr));
	hdr.hdr_entries = htonl(object_count);
	git_SHA1_Update(&new_sha1_ctx, &hdr, sizeof(hdr));
