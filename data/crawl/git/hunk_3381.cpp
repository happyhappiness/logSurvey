 	unsigned long size1, size2;
 	int retval;
 
-	tree1 = read_object_with_reference(old, tree_type, &size1, NULL);
-	if (!tree1)
-		die("unable to read source tree (%s)", sha1_to_hex(old));
-	tree2 = read_object_with_reference(new, tree_type, &size2, NULL);
-	if (!tree2)
-		die("unable to read destination tree (%s)", sha1_to_hex(new));
-	init_tree_desc(&t1, tree1, size1);
-	init_tree_desc(&t2, tree2, size2);
+	tree1 = fill_tree_descriptor(&t1, old);
+	tree2 = fill_tree_descriptor(&t2, new);
+	size1 = t1.size;
+	size2 = t2.size;
 	retval = diff_tree(&t1, &t2, base, opt);
 	if (!*base && DIFF_OPT_TST(opt, FOLLOW_RENAMES) && diff_might_be_rename()) {
 		init_tree_desc(&t1, tree1, size1);