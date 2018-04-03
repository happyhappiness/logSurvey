
	if (msgbuf.len) {
		fwrite(msgbuf.buf, sizeof(char), msgbuf.len, stdout);
		if (opt->use_terminator)
			putchar('\n');
	}
	strbuf_release(&msgbuf);
}
