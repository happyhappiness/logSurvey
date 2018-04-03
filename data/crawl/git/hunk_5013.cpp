 	return compile_pattern_or(list);
 }
 
-void compile_grep_patterns(struct grep_opt *opt)
+static struct grep_expr *prep_header_patterns(struct grep_opt *opt)
 {
 	struct grep_pat *p;
-	struct grep_expr *header_expr = NULL;
-
-	if (opt->header_list) {
-		p = opt->header_list;
-		header_expr = compile_pattern_expr(&p);
-		if (p)
-			die("incomplete pattern expression: %s", p->pattern);
-		for (p = opt->header_list; p; p = p->next) {
-			switch (p->token) {
-			case GREP_PATTERN: /* atom */
-			case GREP_PATTERN_HEAD:
-			case GREP_PATTERN_BODY:
-				compile_regexp(p, opt);
-				break;
-			default:
-				opt->extended = 1;
-				break;
-			}
-		}
+	struct grep_expr *header_expr;
+
+	if (!opt->header_list)
+		return NULL;
+	p = opt->header_list;
+	header_expr = compile_pattern_expr(&p);
+	if (p)
+		die("incomplete pattern expression: %s", p->pattern);
+	for (p = opt->header_list; p; p = p->next) {
+		if (p->token != GREP_PATTERN_HEAD)
+			die("bug: a non-header pattern in grep header list.");
+		if (p->field < 0 || GREP_HEADER_FIELD_MAX <= p->field)
+			die("bug: unknown header field %d", p->field);
+		compile_regexp(p, opt);
 	}
+	return header_expr;
+}
+
+void compile_grep_patterns(struct grep_opt *opt)
+{
+	struct grep_pat *p;
+	struct grep_expr *header_expr = prep_header_patterns(opt);
 
 	for (p = opt->pattern_list; p; p = p->next) {
 		switch (p->token) {
