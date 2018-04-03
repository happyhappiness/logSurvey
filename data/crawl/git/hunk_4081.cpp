 	return compile_pattern_or(list);
 }
 
+static void indent(int in)
+{
+	while (in-- > 0)
+		fputc(' ', stderr);
+}
+
+static void dump_grep_pat(struct grep_pat *p)
+{
+	switch (p->token) {
+	case GREP_AND: fprintf(stderr, "*and*"); break;
+	case GREP_OPEN_PAREN: fprintf(stderr, "*(*"); break;
+	case GREP_CLOSE_PAREN: fprintf(stderr, "*)*"); break;
+	case GREP_NOT: fprintf(stderr, "*not*"); break;
+	case GREP_OR: fprintf(stderr, "*or*"); break;
+
+	case GREP_PATTERN: fprintf(stderr, "pattern"); break;
+	case GREP_PATTERN_HEAD: fprintf(stderr, "pattern_head"); break;
+	case GREP_PATTERN_BODY: fprintf(stderr, "pattern_body"); break;
+	}
+
+	switch (p->token) {
+	default: break;
+	case GREP_PATTERN_HEAD:
+		fprintf(stderr, "<head %d>", p->field); break;
+	case GREP_PATTERN_BODY:
+		fprintf(stderr, "<body>"); break;
+	}
+	switch (p->token) {
+	default: break;
+	case GREP_PATTERN_HEAD:
+	case GREP_PATTERN_BODY:
+	case GREP_PATTERN:
+		fprintf(stderr, "%.*s", (int)p->patternlen, p->pattern);
+		break;
+	}
+	fputc('\n', stderr);
+}
+
+static void dump_grep_expression_1(struct grep_expr *x, int in)
+{
+	indent(in);
+	switch (x->node) {
+	case GREP_NODE_TRUE:
+		fprintf(stderr, "true\n");
+		break;
+	case GREP_NODE_ATOM:
+		dump_grep_pat(x->u.atom);
+		break;
+	case GREP_NODE_NOT:
+		fprintf(stderr, "(not\n");
+		dump_grep_expression_1(x->u.unary, in+1);
+		indent(in);
+		fprintf(stderr, ")\n");
+		break;
+	case GREP_NODE_AND:
+		fprintf(stderr, "(and\n");
+		dump_grep_expression_1(x->u.binary.left, in+1);
+		dump_grep_expression_1(x->u.binary.right, in+1);
+		indent(in);
+		fprintf(stderr, ")\n");
+		break;
+	case GREP_NODE_OR:
+		fprintf(stderr, "(or\n");
+		dump_grep_expression_1(x->u.binary.left, in+1);
+		dump_grep_expression_1(x->u.binary.right, in+1);
+		indent(in);
+		fprintf(stderr, ")\n");
+		break;
+	}
+}
+
+void dump_grep_expression(struct grep_opt *opt)
+{
+	struct grep_expr *x = opt->pattern_expression;
+
+	if (opt->all_match)
+		fprintf(stderr, "[all-match]\n");
+	dump_grep_expression_1(x, 0);
+	fflush(NULL);
+}
+
 static struct grep_expr *grep_true_expr(void)
 {
 	struct grep_expr *z = xcalloc(1, sizeof(*z));
