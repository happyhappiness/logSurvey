
	graph_show_commit(revs->graph);

	if (info->show_timestamp)
		printf("%lu ", commit->date);
	if (info->header_prefix)
