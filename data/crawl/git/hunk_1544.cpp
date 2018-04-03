 static int add_one_reference(struct string_list_item *item, void *cb_data)
 {
 	struct strbuf err = STRBUF_INIT;
-	struct strbuf sb = STRBUF_INIT;
+	int *required = cb_data;
 	char *ref_git = compute_alternate_path(item->string, &err);
 
-	if (!ref_git)
-		die("%s", err.buf);
-
-	strbuf_addf(&sb, "%s/objects", ref_git);
-	add_to_alternates_file(sb.buf);
+	if (!ref_git) {
+		if (*required)
+			die("%s", err.buf);
+		else
+			fprintf(stderr,
+				_("info: Could not add alternate for '%s': %s\n"),
+				item->string, err.buf);
+	} else {
+		struct strbuf sb = STRBUF_INIT;
+		strbuf_addf(&sb, "%s/objects", ref_git);
+		add_to_alternates_file(sb.buf);
+		strbuf_release(&sb);
+	}
 
-	free(ref_git);
 	strbuf_release(&err);
-	strbuf_release(&sb);
+	free(ref_git);
 	return 0;
 }
 
 static void setup_reference(void)
 {
-	for_each_string_list(&option_required_reference, add_one_reference, NULL);
+	int required = 1;
+	for_each_string_list(&option_required_reference,
+			     add_one_reference, &required);
+	required = 0;
+	for_each_string_list(&option_optional_reference,
+			     add_one_reference, &required);
 }
 
 static void copy_alternates(struct strbuf *src, struct strbuf *dst,
