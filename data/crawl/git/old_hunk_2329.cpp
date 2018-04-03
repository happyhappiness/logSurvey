	return 0;
}

static void print_lines(struct strbuf **lines, int start, int end)
{
	int i;
	for (i = start; lines[i] && i < end; i++)
		printf("%s", lines[i]->buf);
}

static int process_input_file(struct strbuf **lines,
			      struct trailer_item **in_tok_first,
			      struct trailer_item **in_tok_last)
{
