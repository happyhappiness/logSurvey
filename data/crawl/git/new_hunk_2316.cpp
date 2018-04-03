
	insert_one_record(log, author.buf, oneline.len ? oneline.buf : "<none>");

	strbuf_release(&author);
	strbuf_release(&oneline);
}
