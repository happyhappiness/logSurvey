	info->message_id = strbuf_detach(&buf, NULL);
}

static void print_signature(FILE *file)
{
	if (!signature || !*signature)
		return;

	fprintf(file, "-- \n%s", signature);
	if (signature[strlen(signature)-1] != '\n')
		putc('\n', file);
	putc('\n', file);
}

static void add_branch_description(struct strbuf *buf, const char *branch_name)
