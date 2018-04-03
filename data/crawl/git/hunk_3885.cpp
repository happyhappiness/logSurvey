 	const char *plain = diff_get_color(ecbdata->color_diff, DIFF_PLAIN);
 	const char *reset = diff_get_color(ecbdata->color_diff, DIFF_RESET);
 	struct diff_options *o = ecbdata->opt;
-	char *line_prefix = "";
-	struct strbuf *msgbuf;
-
-	if (o && o->output_prefix) {
-		msgbuf = o->output_prefix(o, o->output_prefix_data);
-		line_prefix = msgbuf->buf;
-	}
+	const char *line_prefix = diff_line_prefix(o);
 
 	if (ecbdata->header) {
 		fprintf(ecbdata->opt->file, "%s", ecbdata->header->buf);