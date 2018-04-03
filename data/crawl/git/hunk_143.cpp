 		commit_list_insert(current_head, &parents);
 	}
 
-	cleanup = (flags & CLEANUP_MSG) ? COMMIT_MSG_CLEANUP_ALL :
-					  opts->default_msg_cleanup;
-
-	if (cleanup != COMMIT_MSG_CLEANUP_NONE)
-		strbuf_stripspace(msg, cleanup == COMMIT_MSG_CLEANUP_ALL);
-	if (!opts->allow_empty_message && message_is_empty(msg, cleanup)) {
-		res = 1; /* run 'git commit' to display error message */
-		goto out;
-	}
-
 	if (write_cache_as_tree(tree.hash, 0, NULL)) {
 		res = error(_("git write-tree failed to write a tree"));
 		goto out;