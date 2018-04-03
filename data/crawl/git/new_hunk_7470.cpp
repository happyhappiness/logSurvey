		}
		setup_revisions(0, NULL, &revs, NULL);
	}
	if (prepare_revision_walk(&revs))
		die("revision walk setup failed");
	mark_edges_uninteresting(revs.commits, &revs, show_edge);
	traverse_commit_list(&revs, show_commit, show_object);
	return 0;