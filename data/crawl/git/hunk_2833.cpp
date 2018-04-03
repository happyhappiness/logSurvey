 	    revs.diff)
 		usage(rev_list_usage);
 
+	if (revs.show_notes)
+		die(_("rev-list does not support display of notes"));
+
 	save_commit_buffer = (revs.verbose_header ||
 			      revs.grep_filter.pattern_list ||
 			      revs.grep_filter.header_list);