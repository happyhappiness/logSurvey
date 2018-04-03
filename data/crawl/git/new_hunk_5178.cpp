
	graph_show_commit(revs->graph);

	if (revs->count) {
		if (commit->object.flags & SYMMETRIC_LEFT)
			revs->count_left++;
		else
			revs->count_right++;
		finish_commit(commit, data);
		return;
	}

	if (info->show_timestamp)
		printf("%lu ", commit->date);
	if (info->header_prefix)
