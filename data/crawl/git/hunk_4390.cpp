 		graph_show_commit(opt->graph);
 
 		if (!opt->graph)
-			fputs(get_revision_mark(opt, commit), stdout);
+			put_revision_mark(opt, commit);
 		fputs(find_unique_abbrev(commit->object.sha1, abbrev_commit), stdout);
 		if (opt->print_parents)
 			show_parents(commit, abbrev_commit);
