	sb.revs = &revs;
	sb.contents_from = contents_from;
	sb.reverse = reverse;
	setup_scoreboard(&sb, path, &o);
	lno = sb.num_lines;

	if (lno && !range_list.nr)
		string_list_append(&range_list, "1");