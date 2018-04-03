			objects = xrealloc(objects,
					   (nr_objects + nr_unresolved + 1)
					   * sizeof(*objects));
			f = sha1fd(output_fd, curr_pack);
			fix_unresolved_deltas(f, nr_unresolved);
			sprintf(msg, "completed with %d local objects",
				nr_objects - nr_objects_initial);
			stop_progress_msg(&progress, msg);
			sha1close(f, tail_sha1, 0);
			hashcpy(read_sha1, pack_sha1);
			fixup_pack_header_footer(output_fd, pack_sha1,
						 curr_pack, nr_objects,
						 read_sha1, consumed_bytes-20);
			if (hashcmp(read_sha1, tail_sha1) != 0)
				die("Unexpected tail checksum for %s "
				    "(disk corruption?)", curr_pack);
		}
		if (nr_deltas != nr_resolved_deltas)
			die("pack has %d unresolved deltas",
