 		fprintf(stderr, "Checking commit %s\n",
 			sha1_to_hex(commit->object.sha1));
 
+	if (!commit->date)
+		return objerror(&commit->object, "invalid author/committer line");
+
 	if (memcmp(buffer, "tree ", 5))
 		return objerror(&commit->object, "invalid format - expected 'tree' line");
 	if (get_sha1_hex(buffer+5, tree_sha1) || buffer[45] != '\n')
