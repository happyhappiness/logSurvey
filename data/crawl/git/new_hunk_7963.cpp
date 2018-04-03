	if (opt->show_log_size)
		printf("log size %i\n", len);

	if (*msgbuf)
		printf("%s%s%s", msgbuf, extra, sep);
	free(msgbuf);
}

