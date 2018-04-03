	chmod(pack_data->pack_name, 0444);
	chmod(curr_index_name, 0444);

	keep_fd = odb_pack_keep(name, sizeof(name), pack_data->sha1);
	if (keep_fd < 0)
		die("cannot create keep file");
	write_or_die(keep_fd, keep_msg, strlen(keep_msg));
