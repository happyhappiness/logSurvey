		die("Could not run git status --porcelain");

	len = strbuf_read(&buf, cp.out, 1024);
	close(cp.out);

	if (finish_command(&cp))
