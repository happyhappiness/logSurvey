		fprintf(stderr, "Result has %u objects.\n", nr_result);
	if (nr_result)
		prepare_pack(window, depth);
	write_pack_file();
	if (progress)
		fprintf(stderr, "Total %u (delta %u), reused %u (delta %u)\n",
			written, written_delta, reused, reused_delta);