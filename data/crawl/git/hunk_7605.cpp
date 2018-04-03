 	return str;
 }
 
-static void decode_tree_entry(struct tree_desc *desc, const void *buf, unsigned long size)
+static void decode_tree_entry(struct tree_desc *desc, const char *buf, unsigned long size)
 {
 	const char *path;
 	unsigned int mode, len;
 
+	if (size < 24 || buf[size - 21])
+		die("corrupt tree file");
+
 	path = get_mode(buf, &mode);
-	if (!path)
+	if (!path || !*path)
 		die("corrupt tree file");
 	len = strlen(path) + 1;
 