 	int nofirst;
 	FILE *file = o->file;
 
-	if (o->output_prefix) {
-		struct strbuf *msg = NULL;
-		msg = o->output_prefix(o, o->output_prefix_data);
-		assert(msg);
-		fwrite(msg->buf, msg->len, 1, file);
-	}
+	fputs(diff_line_prefix(o), file);
 
 	if (len == 0) {
 		has_trailing_newline = (first == '\n');
