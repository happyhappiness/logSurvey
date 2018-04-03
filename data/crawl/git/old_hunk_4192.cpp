	pass.out = -1;

	if (start_command(&pass))
		exit(1);

	if (strbuf_read(&buffer, pass.out, 20) < 0)
		die("failed to get '%s' from %s\n", prompt, cmd);

	close(pass.out);

	if (finish_command(&pass))
		exit(1);

	strbuf_setlen(&buffer, strcspn(buffer.buf, "\r\n"));

