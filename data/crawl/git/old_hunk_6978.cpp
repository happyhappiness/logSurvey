
	if (unset)
		strbuf_setlen(buf, 0);
	else {
		strbuf_addf(buf, "%s\n\n", arg);
		have_message = 1;
	}
	return 0;
}

