 		}
 	}
 
-	read_cache();
-	init_merge_options(&o);
-	o.ancestor = base ? base_label : "(empty tree)";
-	o.branch1 = "HEAD";
-	o.branch2 = next ? next_label : "(empty tree)";
-
-	head_tree = parse_tree_indirect(head);
-	next_tree = next ? next->tree : empty_tree();
-	base_tree = base ? base->tree : empty_tree();
-
-	clean = merge_trees(&o,
-			    head_tree,
-			    next_tree, base_tree, &result);
-
-	if (active_cache_changed &&
-	    (write_cache(index_fd, active_cache, active_nr) ||
-	     commit_locked_index(&index_lock)))
-		die("%s: Unable to write new index file", me);
-	rollback_lock_file(&index_lock);
-
-	if (!clean) {
-		strbuf_addstr(&msgbuf, "\nConflicts:\n\n");
-		for (i = 0; i < active_nr;) {
-			struct cache_entry *ce = active_cache[i++];
-			if (ce_stage(ce)) {
-				strbuf_addch(&msgbuf, '\t');
-				strbuf_addstr(&msgbuf, ce->name);
-				strbuf_addch(&msgbuf, '\n');
-				while (i < active_nr && !strcmp(ce->name,
-						active_cache[i]->name))
-					i++;
-			}
-		}
-		write_message(&msgbuf, defmsg);
-		fprintf(stderr, "Automatic %s failed.%s\n",
-			me, help_msg(commit_name));
-		rerere(allow_rerere_auto);
-		exit(1);
-	}
-	write_message(&msgbuf, defmsg);
-	fprintf(stderr, "Finished one %s.\n", me);
+	do_recursive_merge(base, next, base_label, next_label,
+			   head, &msgbuf, defmsg);
 
 	/*
 	 *