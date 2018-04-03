
		/* Generate a list of objects that need to be pushed */
		pushing = 0;
		if (prepare_revision_walk(&revs))
			die("revision walk setup failed");
		mark_edges_uninteresting(revs.commits);
		objects_to_send = get_delta(&revs, ref_lock);
		finish_all_active_slots();
