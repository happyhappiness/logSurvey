 		}
 	}
 
-	do_recursive_merge(base, next, base_label, next_label,
-			   head, &msgbuf, defmsg);
+	if (!strategy || !strcmp(strategy, "recursive") || action == REVERT)
+		do_recursive_merge(base, next, base_label, next_label,
+				   head, &msgbuf, defmsg);
+	else {
+		int res;
+		struct commit_list *common = NULL;
+		struct commit_list *remotes = NULL;
+		write_message(&msgbuf, defmsg);
+		commit_list_insert(base, &common);
+		commit_list_insert(next, &remotes);
+		res = try_merge_command(strategy, common,
+					sha1_to_hex(head), remotes);
+		free_commit_list(common);
+		free_commit_list(remotes);
+		if (res) {
+			fprintf(stderr, "Automatic %s with strategy %s failed.%s\n",
+				me, strategy, help_msg(commit_name));
+			rerere(allow_rerere_auto);
+			exit(1);
+		}
+	}
 
 	/*
 	 *