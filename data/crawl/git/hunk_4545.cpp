 	struct commit_list *parent = xmalloc(sizeof(*parent));
 
 	write_tree_trivial(result_tree);
-	printf("Wonderful.\n");
+	printf(_("Wonderful.\n"));
 	parent->item = lookup_commit(head);
 	parent->next = xmalloc(sizeof(*parent->next));
 	parent->next->item = remoteheads->item;
