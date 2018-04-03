	if (cnt < reaches)
		cnt = reaches;

	if (revs->commits)
		strcpy(hex, sha1_to_hex(revs->commits->item->object.sha1));

	if (show_all) {
		traverse_commit_list(revs, show_commit, show_object);
		printf("------\n");
	}

	if (show_tried)
		show_tried_revs(tried);
	printf("bisect_rev=%s\n"
	       "bisect_nr=%d\n"
	       "bisect_good=%d\n"
