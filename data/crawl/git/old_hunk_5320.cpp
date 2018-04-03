	child.use_shell = 1;
	child.argv = argv;
	child.out = -1;
	if (start_command(&child) != 0 ||
	    strbuf_read(&buf, child.out, 0) < 0 ||
	    finish_command(&child) != 0) {
		close(child.out);
		strbuf_release(&buf);
		remove_tempfile();
		error("error running textconv command '%s'", pgm);
		return NULL;
	}
	close(child.out);
	remove_tempfile();

	return strbuf_detach(&buf, outsize);
