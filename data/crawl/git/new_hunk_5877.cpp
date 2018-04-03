	}

	if (strbuf_read(&input, fileno(in), 0) < 0)
		die_errno("could not read input file");
	ret = fmt_merge_msg(merge_summary, &input, &output);
	if (ret)
		return ret;
