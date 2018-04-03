	}

	if (flags & BISECT_SHOW_TRIED)
		show_tried_revs(tried);
	printf("bisect_rev=%s\n"
	       "bisect_nr=%d\n"
	       "bisect_good=%d\n"
	       "bisect_bad=%d\n"
	       "bisect_all=%d\n"
	       "bisect_steps=%d\n",
	       hex,
	       cnt - 1,
	       all - reaches - 1,
