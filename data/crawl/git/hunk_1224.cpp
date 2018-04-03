 			continue;
 
 		/* Ok, we'll consider it a patch */
-		parse_traditional_patch(line, line+len, patch);
+		parse_traditional_patch(state, line, line+len, patch);
 		*hdrsize = len + nextlen;
-		linenr += 2;
+		state->linenr += 2;
 		return offset;
 	}
 	return -1;
 }
 
-static void record_ws_error(unsigned result, const char *line, int len, int linenr)
+static void record_ws_error(struct apply_state *state,
+			    unsigned result,
+			    const char *line,
+			    int len,
+			    int linenr)
 {
 	char *err;
 
 	if (!result)
 		return;
 
-	whitespace_error++;
-	if (squelch_whitespace_errors &&
-	    squelch_whitespace_errors < whitespace_error)
+	state->whitespace_error++;
+	if (state->squelch_whitespace_errors &&
+	    state->squelch_whitespace_errors < state->whitespace_error)
 		return;
 
 	err = whitespace_error_string(result);
 	fprintf(stderr, "%s:%d: %s.\n%.*s\n",
-		patch_input_file, linenr, err, len, line);
+		state->patch_input_file, linenr, err, len, line);
 	free(err);
 }
 
-static void check_whitespace(const char *line, int len, unsigned ws_rule)
+static void check_whitespace(struct apply_state *state,
+			     const char *line,
+			     int len,
+			     unsigned ws_rule)
 {
 	unsigned result = ws_check(line + 1, len - 1, ws_rule);
 
-	record_ws_error(result, line + 1, len - 2, linenr);
+	record_ws_error(state, result, line + 1, len - 2, state->linenr);
 }
 
 /*
