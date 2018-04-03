 				printf("    %s\n", states.heads.items[i].string);
 		}
 
-		for (i = 0; i < branch_list.nr; i++) {
-			struct string_list_item *branch = branch_list.items + i;
-			struct branch_info *info = branch->util;
-			int j;
-
-			if (!info->merge.nr || strcmp(*argv, info->remote_name))
-				continue;
-			printf("  Remote branch%s merged with 'git pull' "
-				"while on branch %s\n   ",
-				info->merge.nr > 1 ? "es" : "",
-				branch->string);
-			for (j = 0; j < info->merge.nr; j++)
-				printf(" %s", info->merge.items[j].string);
-			printf("\n");
-		}
-
-		if (!no_query) {
-			show_list("  New remote branch%s (next fetch "
-				"will store in remotes/%s)",
-				&states.new, states.remote->name);
-			show_list("  Stale tracking branch%s (use 'git remote "
-				"prune')", &states.stale, "");
-		}
-
-		show_list("  Tracked remote branch%s", &states.tracked, "");
-
+		/* remote branch info */
+		info.width = 0;
+		for_each_string_list(add_remote_to_show_info, &states.new, &info);
+		for_each_string_list(add_remote_to_show_info, &states.tracked, &info);
+		for_each_string_list(add_remote_to_show_info, &states.stale, &info);
+		if (info.list->nr)
+			printf("  Remote branch%s:%s\n",
+			       info.list->nr > 1 ? "es" : "",
+				no_query ? " (status not queried)" : "");
+		for_each_string_list(show_remote_info_item, info.list, &info);
+		string_list_clear(info.list, 0);
+
+		/* git pull info */
+		info.width = 0;
+		info.any_rebase = 0;
+		for_each_string_list(add_local_to_show_info, &branch_list, &info);
+		if (info.list->nr)
+			printf("  Local branch%s configured for 'git pull':\n",
+			       info.list->nr > 1 ? "es" : "");
+		for_each_string_list(show_local_info_item, info.list, &info);
+		string_list_clear(info.list, 0);
+
+		/* git push info */
 		if (states.remote->push_refspec_nr) {
 			printf("  Local branch%s pushed with 'git push'\n",
 				states.remote->push_refspec_nr > 1 ?
