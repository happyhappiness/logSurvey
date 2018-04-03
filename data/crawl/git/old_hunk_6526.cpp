
struct diff_words_data {
	struct diff_words_buffer minus, plus;
	FILE *file;
};

static void print_word(FILE *file, struct diff_words_buffer *buffer, int len, int color,
		int suppress_newline)
{
	const char *ptr;
	int eol = 0;

	if (len == 0)
		return;

	ptr  = buffer->text.ptr + buffer->current;
	buffer->current += len;

	if (ptr[len - 1] == '\n') {
		eol = 1;
		len--;
	}

	fputs(diff_get_color(1, color), file);
	fwrite(ptr, len, 1, file);
	fputs(diff_get_color(1, DIFF_RESET), file);

	if (eol) {
		if (suppress_newline)
			buffer->suppressed_newline = 1;
		else
			putc('\n', file);
	}
}

static void fn_out_diff_words_aux(void *priv, char *line, unsigned long len)
{
	struct diff_words_data *diff_words = priv;

	if (diff_words->minus.suppressed_newline) {
		if (line[0] != '+')
			putc('\n', diff_words->file);
		diff_words->minus.suppressed_newline = 0;
	}

	len--;
	switch (line[0]) {
		case '-':
			print_word(diff_words->file,
				   &diff_words->minus, len, DIFF_FILE_OLD, 1);
			break;
		case '+':
			print_word(diff_words->file,
				   &diff_words->plus, len, DIFF_FILE_NEW, 0);
			break;
		case ' ':
			print_word(diff_words->file,
				   &diff_words->plus, len, DIFF_PLAIN, 0);
			diff_words->minus.current += len;
			break;
	}
}

/*
 * This function splits the words in buffer->text, and stores the list with
 * newline separator into out.
 */
static void diff_words_fill(struct diff_words_buffer *buffer, mmfile_t *out)
{
	int i;
	out->size = buffer->text.size;
	out->ptr = xmalloc(out->size);
	memcpy(out->ptr, buffer->text.ptr, out->size);
	for (i = 0; i < out->size; i++)
		if (isspace(out->ptr[i]))
			out->ptr[i] = '\n';
	buffer->current = 0;
}

/* this executes the word diff on the accumulated buffers */
