 	desc->buffer = buf;
 	desc->size = size;
 	if (size)
-		decode_tree_entry(desc, buf, size);
+		return decode_tree_entry(desc, buf, size, err);
+	return 0;
+}
+
+void update_tree_entry(struct tree_desc *desc)
+{
+	struct strbuf err = STRBUF_INIT;
+	if (update_tree_entry_internal(desc, &err))
+		die("%s", err.buf);
+	strbuf_release(&err);
+}
+
+int update_tree_entry_gently(struct tree_desc *desc)
+{
+	struct strbuf err = STRBUF_INIT;
+	if (update_tree_entry_internal(desc, &err)) {
+		error("%s", err.buf);
+		strbuf_release(&err);
+		/* Stop processing this tree after error */
+		desc->size = 0;
+		return -1;
+	}
+	strbuf_release(&err);
+	return 0;
 }
 
 int tree_entry(struct tree_desc *desc, struct name_entry *entry)
