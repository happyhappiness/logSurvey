	/* perhaps other traits later as well */
	fprintf(cbdata.refs_file, "# pack-refs with: peeled fully-peeled \n");

	for_each_ref(pack_one_ref, &cbdata);
	if (ferror(cbdata.refs_file))
		die("failed to write ref-pack file");
	if (fflush(cbdata.refs_file) || fsync(fd) || fclose(cbdata.refs_file))