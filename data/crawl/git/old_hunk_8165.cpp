	if (opt->add_signoff)
		len = append_signoff(&msgbuf, &msgbuf_len, len,
				     opt->add_signoff);
	printf("%s%s%s", msgbuf, extra, sep);
	free(msgbuf);
}
