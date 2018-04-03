			    nr_objects - nr_objects_initial);
		stop_progress_msg(&progress, msg.buf);
		strbuf_release(&msg);
		sha1close(f, tail_sha1, 0);
		hashcpy(read_sha1, pack_sha1);
		fixup_pack_header_footer(output_fd, pack_sha1,
					 curr_pack, nr_objects,
					 read_sha1, consumed_bytes-20);
		if (hashcmp(read_sha1, tail_sha1) != 0)
			die(_("Unexpected tail checksum for %s "
			      "(disk corruption?)"), curr_pack);
	}
