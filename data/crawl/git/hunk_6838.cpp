 
 static void emit_line(FILE *file, const char *set, const char *reset, const char *line, int len)
 {
-	int has_trailing_newline = (len > 0 && line[len-1] == '\n');
+	int has_trailing_newline, has_trailing_carriage_return;
+
+	has_trailing_newline = (len > 0 && line[len-1] == '\n');
 	if (has_trailing_newline)
 		len--;
+	has_trailing_carriage_return = (len > 0 && line[len-1] == '\r');
+	if (has_trailing_carriage_return)
+		len--;
 
 	fputs(set, file);
 	fwrite(line, len, 1, file);
 	fputs(reset, file);
+	if (has_trailing_carriage_return)
+		fputc('\r', file);
 	if (has_trailing_newline)
 		fputc('\n', file);
 }
