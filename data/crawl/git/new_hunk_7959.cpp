	if (run_command(&child))
		die("There was a problem with the editor %s.", editor);

	if (strbuf_read_file(buffer, path) < 0)
		die("could not read message file '%s': %s",
		    path, strerror(errno));
}

struct tag_filter {
