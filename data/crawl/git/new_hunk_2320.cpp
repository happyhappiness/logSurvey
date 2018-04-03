
static void read_from_stdin(struct shortlog *log)
{
	struct strbuf author = STRBUF_INIT;
	struct strbuf oneline = STRBUF_INIT;

	while (strbuf_getline(&author, stdin, '\n') != EOF) {
		const char *v;
		if (!skip_prefix(author.buf, "Author: ", &v) &&
		    !skip_prefix(author.buf, "author ", &v))
			continue;
		while (strbuf_getline(&oneline, stdin, '\n') != EOF &&
		       oneline.len)
			; /* discard headers */
		while (strbuf_getline(&oneline, stdin, '\n') != EOF &&
		       !oneline.len)
			; /* discard blanks */
		insert_one_record(log, v, oneline.buf);
	}
	strbuf_release(&author);
	strbuf_release(&oneline);
}

void shortlog_add_commit(struct shortlog *log, struct commit *commit)