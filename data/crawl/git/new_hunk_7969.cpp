	fputc('\'', stream);
}

void sq_quote_argv(struct strbuf *dst, const char** argv, int count,
                   size_t maxlen)
{
	int i;

	/* Count argv if needed. */
	if (count < 0) {
		for (count = 0; argv[count]; count++)
			; /* just counting */
	}

	/* Copy into destination buffer. */
	strbuf_grow(dst, 32 * count);
	for (i = 0; i < count; ++i) {
		strbuf_addch(dst, ' ');
		sq_quote_buf(dst, argv[i]);
		if (maxlen && dst->len > maxlen)
			die("Too many or long arguments");
	}
}

char *sq_dequote(char *arg)
