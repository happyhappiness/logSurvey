 		die(_("Cannot rebase onto multiple branches."));
 
 	if (opt_rebase) {
+		int ret = 0;
+		if ((recurse_submodules == RECURSE_SUBMODULES_ON ||
+		     recurse_submodules == RECURSE_SUBMODULES_ON_DEMAND) &&
+		    submodule_touches_in_range(&rebase_fork_point, &curr_head))
+			die(_("cannot rebase with locally recorded submodule modifications"));
 		if (!autostash) {
 			struct commit_list *list = NULL;
 			struct commit *merge_head, *head;
