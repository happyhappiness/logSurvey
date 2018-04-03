	buffer->text.ptr[buffer->text.size] = '\0';
}

struct diff_words_data {
	struct diff_words_buffer minus, plus;
	const char *current_plus;
	FILE *file;
	regex_t *word_regex;
};

static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
{
	struct diff_words_data *diff_words = priv;
	int minus_first, minus_len, plus_first, plus_len;
	const char *minus_begin, *minus_end, *plus_begin, *plus_end;

