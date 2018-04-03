 	if (strbuf_read(&buffer, 0, 0) < 0)
 		die_errno("git commit-tree: failed to read");
 
-	if (!commit_tree(buffer.buf, tree_sha1, parents, commit_sha1, NULL)) {
-		printf("%s\n", sha1_to_hex(commit_sha1));
-		return 0;
-	}
-	else
+	if (commit_tree(buffer.buf, tree_sha1, parents, commit_sha1, NULL)) {
+		strbuf_release(&buffer);
 		return 1;
+	}
+
+	printf("%s\n", sha1_to_hex(commit_sha1));
+	strbuf_release(&buffer);
+	return 0;
 }