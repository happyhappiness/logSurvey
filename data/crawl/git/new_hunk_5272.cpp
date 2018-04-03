	buffer->text.ptr[buffer->text.size] = '\0';
}

struct diff_words_style_elem
{
	const char *prefix;
	const char *suffix;
	const char *color; /* NULL; filled in by the setup code if
			    * color is enabled */
};

struct diff_words_style
{
	enum diff_words_type type;
	struct diff_words_style_elem new, old, ctx;
	const char *newline;
};

struct diff_words_style diff_words_styles[] = {
	{ DIFF_WORDS_PORCELAIN, {"+", "\n"}, {"-", "\n"}, {" ", "\n"}, "~\n" },
	{ DIFF_WORDS_PLAIN, {"{+", "+}"}, {"[-", "-]"}, {"", ""}, "\n" },
	{ DIFF_WORDS_COLOR, {"", ""}, {"", ""}, {"", ""}, "\n" }
};

struct diff_words_data {
	struct diff_words_buffer minus, plus;
	const char *current_plus;
	FILE *file;
	regex_t *word_regex;
	enum diff_words_type type;
	struct diff_words_style *style;
};

static int fn_out_diff_words_write_helper(FILE *fp,
					  struct diff_words_style_elem *st_el,
					  const char *newline,
					  size_t count, const char *buf)
{
	while (count) {
		char *p = memchr(buf, '\n', count);
		if (p != buf) {
			if (st_el->color && fputs(st_el->color, fp) < 0)
				return -1;
			if (fputs(st_el->prefix, fp) < 0 ||
			    fwrite(buf, p ? p - buf : count, 1, fp) != 1 ||
			    fputs(st_el->suffix, fp) < 0)
				return -1;
			if (st_el->color && *st_el->color
			    && fputs(GIT_COLOR_RESET, fp) < 0)
				return -1;
		}
		if (!p)
			return 0;
		if (fputs(newline, fp) < 0)
			return -1;
		count -= p + 1 - buf;
		buf = p + 1;
	}
	return 0;
}

static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
{
	struct diff_words_data *diff_words = priv;
	struct diff_words_style *style = diff_words->style;
	int minus_first, minus_len, plus_first, plus_len;
	const char *minus_begin, *minus_end, *plus_begin, *plus_end;

