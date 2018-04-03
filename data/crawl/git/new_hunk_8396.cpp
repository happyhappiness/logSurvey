	idx_tmp_name = xstrdup(tmpname);
	f = sha1fd(fd, idx_tmp_name);

	if (nr_written) {
		sorted_by_sha = written_list;
		qsort(sorted_by_sha, nr_written, sizeof(*sorted_by_sha), sha1_sort);
		list = sorted_by_sha;
		last = sorted_by_sha + nr_written;
	} else
		sorted_by_sha = list = last = NULL;

