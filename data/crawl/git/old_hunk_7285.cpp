	if (opt->show_log_size)
		printf("log size %i\n", (int)msgbuf.len);

	if (msgbuf.len)
		printf("%s%s%s", msgbuf.buf, extra, sep);
	strbuf_release(&msgbuf);
}

