 
 static void check_whitespace(const char *line, int len, unsigned ws_rule)
 {
-	const char *err = "Adds trailing whitespace";
-	int seen_space = 0;
-	int i;
-
-	/*
-	 * We know len is at least two, since we have a '+' and we
-	 * checked that the last character was a '\n' before calling
-	 * this function.  That is, an addition of an empty line would
-	 * check the '+' here.  Sneaky...
-	 */
-	if ((ws_rule & WS_TRAILING_SPACE) && isspace(line[len-2]))
-		goto error;
-
-	/*
-	 * Make sure that there is no space followed by a tab in
-	 * indentation.
-	 */
-	if (ws_rule & WS_SPACE_BEFORE_TAB) {
-		err = "Space in indent is followed by a tab";
-		for (i = 1; i < len; i++) {
-			if (line[i] == '\t') {
-				if (seen_space)
-					goto error;
-			}
-			else if (line[i] == ' ')
-				seen_space = 1;
-			else
-				break;
-		}
-	}
-
-	/*
-	 * Make sure that the indentation does not contain more than
-	 * 8 spaces.
-	 */
-	if ((ws_rule & WS_INDENT_WITH_NON_TAB) &&
-	    (8 < len) && !strncmp("+        ", line, 9)) {
-		err = "Indent more than 8 places with spaces";
-		goto error;
-	}
-	return;
+	char *err;
+	unsigned result = check_and_emit_line(line + 1, len - 1, ws_rule,
+	    NULL, NULL, NULL, NULL);
+	if (!result)
+		return;
 
- error:
 	whitespace_error++;
 	if (squelch_whitespace_errors &&
 	    squelch_whitespace_errors < whitespace_error)
 		;
-	else
+	else {
+		err = whitespace_error_string(result);
 		fprintf(stderr, "%s.\n%s:%d:%.*s\n",
-			err, patch_input_file, linenr, len-2, line+1);
+		     err, patch_input_file, linenr, len - 2, line + 1);
+		free(err);
+	}
 }
 
 /*
