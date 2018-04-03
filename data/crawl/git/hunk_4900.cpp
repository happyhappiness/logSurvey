 		usage("test-treap < ints");
 
 	while (strbuf_getline(&sb, stdin, '\n') != EOF) {
-		item = node_alloc(1);
-		strtonode(node_pointer(item), sb.buf);
-		treap_insert(&root, node_pointer(item));
+		struct int_node *node = node_pointer(node_alloc(1));
+
+		item = node_offset(node);
+		strtonode(node, sb.buf);
+		node = treap_insert(&root, node_pointer(item));
+		if (node_offset(node) != item)
+			die("inserted %"PRIu32" in place of %"PRIu32"",
+				node_offset(node), item);
 	}
 
 	item = node_offset(treap_first(&root));
