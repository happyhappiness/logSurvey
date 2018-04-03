	unsigned in_vain = 0;
	int got_continue = 0;
	struct strbuf req_buf = STRBUF_INIT;

	if (marked)
		for_each_ref(clear_marks, NULL);
	marked = 1;
