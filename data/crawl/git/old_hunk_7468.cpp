
		/* Generate a list of objects that need to be pushed */
		pushing = 0;
		prepare_revision_walk(&revs);
		mark_edges_uninteresting(revs.commits);
		objects_to_send = get_delta(&revs, ref_lock);
		finish_all_active_slots();
