	fprintf(cbdata.refs_file, "# pack-refs with: peeled \n");

	for_each_ref(handle_one_ref, &cbdata);
	if (fflush(cbdata.refs_file) || fsync(fd) || fclose(cbdata.refs_file))
		die("failed to write ref-pack file (%s)", strerror(errno));
	if (commit_lock_file(&packed) < 0)