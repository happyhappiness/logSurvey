			die("bad revision '%s'", line);
	}

	if (use_bitmap_index && !get_object_list_from_bitmap(&revs))
		return;

	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	mark_edges_uninteresting(&revs, show_edge);
