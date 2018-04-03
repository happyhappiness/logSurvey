	prepare_packed_git();

	if (progress)
		start_progress(&progress_state, "Generating pack...",
			       "Counting objects: ", 0);
	if (!use_internal_rev_list)
		read_object_list_from_stdin();
	else {
		rp_av[rp_ac] = NULL;
		get_object_list(rp_ac, rp_av);
	}
	if (progress) {
		stop_progress(&progress_state);
		fprintf(stderr, "Done counting %u objects.\n", nr_objects);
	}

	if (non_empty && !nr_result)
		return 0;
	if (progress && (nr_objects != nr_result))
		fprintf(stderr, "Result has %u objects.\n", nr_result);
	if (nr_result)
		prepare_pack(window, depth);
	write_pack_file();
