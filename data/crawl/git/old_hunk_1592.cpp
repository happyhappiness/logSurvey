		*nongit_ok = 0;

	if (strbuf_getcwd(&cwd))
		die_errno("Unable to read current working directory");
	offset = cwd.len;

	/*
