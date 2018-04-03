	if (start_command(&child) != 0 ||
	    strbuf_read(&buf, child.out, 0) < 0 ||
	    finish_command(&child) != 0) {
		remove_tempfile();
		error("error running textconv command '%s'", pgm);
		return NULL;
	}
	remove_tempfile();

	return strbuf_detach(&buf, outsize);
}