 	const char *line_prefix = diff_line_prefix(o);
 
 	if (ecbdata->header) {
-		fprintf(ecbdata->opt->file, "%s", ecbdata->header->buf);
+		fprintf(o->file, "%s", ecbdata->header->buf);
 		strbuf_reset(ecbdata->header);
 		ecbdata->header = NULL;
 	}
