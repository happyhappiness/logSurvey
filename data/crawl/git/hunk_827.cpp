 		if (save_todo(todo_list, opts))
 			return -1;
 		if (is_rebase_i(opts)) {
+			if (item->command != TODO_COMMENT)
+				fprintf(stderr, "Rebasing (%d/%d)%s",
+					++(todo_list->done_nr),
+					todo_list->total_nr,
+					opts->verbose ? "\n" : "\r");
 			unlink(rebase_path_message());
 			unlink(rebase_path_author_script());
 			unlink(rebase_path_stopped_sha());