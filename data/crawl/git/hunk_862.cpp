 		struct todo_item *item = todo_list->items + todo_list->current;
 		if (save_todo(todo_list, opts))
 			return -1;
-		res = do_pick_commit(item->command, item->commit, opts);
+		if (item->command <= TODO_REVERT)
+			res = do_pick_commit(item->command, item->commit,
+					opts);
+		else if (!is_noop(item->command))
+			return error(_("unknown command %d"), item->command);
+
 		todo_list->current++;
 		if (res)
 			return res;