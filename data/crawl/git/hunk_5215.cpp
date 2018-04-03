 static int fn_out_diff_words_write_helper(FILE *fp,
 					  struct diff_words_style_elem *st_el,
 					  const char *newline,
-					  size_t count, const char *buf)
+					  size_t count, const char *buf,
+					  const char *line_prefix)
 {
+	int print = 0;
+
 	while (count) {
 		char *p = memchr(buf, '\n', count);
+		if (print)
+			fputs(line_prefix, fp);
 		if (p != buf) {
 			if (st_el->color && fputs(st_el->color, fp) < 0)
 				return -1;
