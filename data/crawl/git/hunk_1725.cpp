 	 * anyway because we don't know if the error explanation part
 	 * will be printed in update_local_ref)
 	 */
+	if (compact_format) {
+		llen = 0;
+		max = max * 2 / 3;
+	}
 	len = 21 /* flag and summary */ + rlen + 4 /* -> */ + llen;
 	if (len >= max)
 		return;
 
+	/*
+	 * Not precise calculation for compact mode because '*' can
+	 * appear on the left hand side of '->' and shrink the column
+	 * back.
+	 */
 	if (refcol_width < rlen)
 		refcol_width = rlen;
 }
 
 static void prepare_format_display(struct ref *ref_map)
 {
 	struct ref *rm;
+	const char *format = "full";
+
+	git_config_get_string_const("fetch.output", &format);
+	if (!strcasecmp(format, "full"))
+		compact_format = 0;
+	else if (!strcasecmp(format, "compact"))
+		compact_format = 1;
+	else
+		die(_("configuration fetch.output contains invalid value %s"),
+		    format);
 
 	for (rm = ref_map; rm; rm = rm->next) {
 		if (rm->status == REF_STATUS_REJECT_SHALLOW ||
