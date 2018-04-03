	}

	if (strbuf_read(&input, fileno(in), 0) < 0)
		die("could not read input file %s", strerror(errno));

	ret = fmt_merge_msg(merge_summary, &input, &output);
	if (ret)
		return ret;
