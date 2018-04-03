	return compile_pattern_or(list);
}

static struct grep_expr *grep_true_expr(void)
{
	struct grep_expr *z = xcalloc(1, sizeof(*z));
