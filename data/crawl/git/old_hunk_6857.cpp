				nr_objects - nr_objects_initial);
			stop_progress_msg(&progress, msg);
			fixup_pack_header_footer(output_fd, sha1,
						 curr_pack, nr_objects);
		}
		if (nr_deltas != nr_resolved_deltas)
			die("pack has %d unresolved deltas",
