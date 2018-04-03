	SHA1_Final(pack_file_sha1, &c);
	write_or_die(pack_fd, pack_file_sha1, 20);
}
