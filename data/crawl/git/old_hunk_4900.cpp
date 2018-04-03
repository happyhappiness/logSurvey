		usage("test-treap < ints");

	while (strbuf_getline(&sb, stdin, '\n') != EOF) {
		item = node_alloc(1);
		strtonode(node_pointer(item), sb.buf);
		treap_insert(&root, node_pointer(item));
	}

	item = node_offset(treap_first(&root));
