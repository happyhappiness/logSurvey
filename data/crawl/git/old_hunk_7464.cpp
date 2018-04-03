			die("bad revision '%s'", line);
	}

	prepare_revision_walk(&revs);
	mark_edges_uninteresting(revs.commits, &revs, show_edge);
	traverse_commit_list(&revs, show_commit, show_object);

