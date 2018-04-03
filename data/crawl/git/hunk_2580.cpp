 
 		if (!opt->graph)
 			put_revision_mark(opt, commit);
-		fputs(find_unique_abbrev(commit->object.sha1, abbrev_commit), stdout);
+		fputs(find_unique_abbrev(get_object_hash(commit->object), abbrev_commit), stdout);
 		if (opt->print_parents)
 			show_parents(commit, abbrev_commit);
 		if (opt->children.name)