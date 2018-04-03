	chmod(pack_data->pack_name, 0444);
	chmod(curr_index_name, 0444);

	snprintf(name, sizeof(name), "%s/pack/pack-%s.keep",
		 get_object_directory(), sha1_to_hex(pack_data->sha1));
	keep_fd = open(name, O_RDWR|O_CREAT|O_EXCL, 0600);
	if (keep_fd < 0)
		die("cannot create keep file");
	write_or_die(keep_fd, keep_msg, strlen(keep_msg));
