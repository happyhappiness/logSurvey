
	if (opt->add_signoff)
		append_signoff(&msgbuf, opt->add_signoff);
	if (opt->show_log_size)
		printf("log size %i\n", (int)msgbuf.len);

	if (msgbuf.len)
		fwrite(msgbuf.buf, sizeof(char), msgbuf.len, stdout);
	if (opt->use_terminator)
		putchar('\n');
	strbuf_release(&msgbuf);
}

