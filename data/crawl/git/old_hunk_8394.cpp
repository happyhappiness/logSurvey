
static void write_pack_file(void)
{
	uint32_t i;
	struct sha1file *f;
	off_t offset, last_obj_offset = 0;
	struct pack_header hdr;
	int do_progress = progress;

	if (pack_to_stdout) {
		f = sha1fd(1, "<stdout>");
		do_progress >>= 1;
	} else {
		int fd = open_object_dir_tmp("tmp_pack_XXXXXX");
		if (fd < 0)
			die("unable to create %s: %s\n", tmpname, strerror(errno));
		pack_tmp_name = xstrdup(tmpname);
		f = sha1fd(fd, pack_tmp_name);
	}

	if (do_progress)
		start_progress(&progress_state, "Writing %u objects...", "", nr_result);

	hdr.hdr_signature = htonl(PACK_SIGNATURE);
	hdr.hdr_version = htonl(PACK_VERSION);
	hdr.hdr_entries = htonl(nr_result);
	sha1write(f, &hdr, sizeof(hdr));
	offset = sizeof(hdr);
	if (!nr_result)
		goto done;
	for (i = 0; i < nr_objects; i++) {
		last_obj_offset = offset;
		offset = write_one(f, objects + i, offset);
		if (do_progress)
			display_progress(&progress_state, written);
	}
	if (do_progress)
		stop_progress(&progress_state);
 done:
	if (written != nr_result)
		die("wrote %u objects while expecting %u", written, nr_result);
	sha1close(f, pack_file_sha1, 1);

	if (!pack_to_stdout) {
			unsigned char object_list_sha1[20];
			mode_t mode = umask(0);

