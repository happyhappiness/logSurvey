	ret = fmt_merge_msg(merge_summary, &input, &output);
	if (ret)
		return ret;
	printf("%s", output.buf);
	return 0;
}