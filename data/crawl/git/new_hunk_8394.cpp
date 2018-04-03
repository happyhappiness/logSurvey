
static void write_pack_file(void)
{
	uint32_t i = 0, j;
	struct sha1file *f;
	off_t offset, offset_one, last_obj_offset = 0;
	struct pack_header hdr;
	int do_progress = progress >> pack_to_stdout;
	uint32_t nr_remaining = nr_result;

	if (do_progress)
		start_progress(&progress_state, "Writing %u objects...", "", nr_result);
	written_list = xmalloc(nr_objects * sizeof(struct object_entry *));

	do {
		if (pack_to_stdout) {
			f = sha1fd(1, "<stdout>");
		} else {
			int fd = open_object_dir_tmp("tmp_pack_XXXXXX");
			if (fd < 0)
				die("unable to create %s: %s\n", tmpname, strerror(errno));
			pack_tmp_name = xstrdup(tmpname);
			f = sha1fd(fd, pack_tmp_name);
		}

		hdr.hdr_signature = htonl(PACK_SIGNATURE);
		hdr.hdr_version = htonl(PACK_VERSION);
		hdr.hdr_entries = htonl(nr_remaining);
		sha1write(f, &hdr, sizeof(hdr));
		offset = sizeof(hdr);
		nr_written = 0;
		for (; i < nr_objects; i++) {
			last_obj_offset = offset;
			offset_one = write_one(f, objects + i, offset);
			if (!offset_one)
				break;
			offset = offset_one;
			if (do_progress)
				display_progress(&progress_state, written);
		}

		/*
		 * Did we write the wrong # entries in the header?
		 * If so, rewrite it like in fast-import
		 */
		if (pack_to_stdout || nr_written == nr_remaining) {
			sha1close(f, pack_file_sha1, 1);
		} else {
			sha1close(f, pack_file_sha1, 0);
			fixup_pack_header_footer(f->fd, pack_file_sha1, pack_tmp_name, nr_written);
			close(f->fd);
		}

		if (!pack_to_stdout) {
			unsigned char object_list_sha1[20];
			mode_t mode = umask(0);

