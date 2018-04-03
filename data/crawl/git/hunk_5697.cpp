 	return -1;
 }
 
-static void check_whitespace(const char *line, int len, unsigned ws_rule)
+static void record_ws_error(unsigned result, const char *line, int len, int linenr)
 {
 	char *err;
-	unsigned result = ws_check(line + 1, len - 1, ws_rule);
+
 	if (!result)
 		return;
 
 	whitespace_error++;
 	if (squelch_whitespace_errors &&
 	    squelch_whitespace_errors < whitespace_error)
-		;
-	else {
-		err = whitespace_error_string(result);
-		fprintf(stderr, "%s:%d: %s.\n%.*s\n",
-			patch_input_file, linenr, err, len - 2, line + 1);
-		free(err);
-	}
+		return;
+
+	err = whitespace_error_string(result);
+	fprintf(stderr, "%s:%d: %s.\n%.*s\n",
+		patch_input_file, linenr, err, len, line);
+	free(err);
+}
+
+static void check_whitespace(const char *line, int len, unsigned ws_rule)
+{
+	unsigned result = ws_check(line + 1, len - 1, ws_rule);
+
+	record_ws_error(result, line + 1, len - 2, linenr);
 }
 
 /*