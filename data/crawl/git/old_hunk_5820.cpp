	if (inpath && strcmp(inpath, "-")) {
		in = fopen(inpath, "r");
		if (!in)
			die("cannot open %s", inpath);
	}

	if (strbuf_read(&input, fileno(in), 0) < 0)
