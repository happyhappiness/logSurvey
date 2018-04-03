		die(_("unable to start 'show' for object '%s'"),
		    sha1_to_hex(object));

	/* Open the output as FILE* so strbuf_getline() can be used. */
	show_out = xfdopen(show.out, "r");
	if (show_out == NULL)
		die_errno(_("can't fdopen 'show' output fd"));

	/* Prepend "# " to each output line and write result to 'fd' */
	while (strbuf_getline(&buf, show_out, '\n') != EOF) {
		write_or_die(fd, "# ", 2);
		write_or_die(fd, buf.buf, buf.len);
		write_or_die(fd, "\n", 1);
	}
	strbuf_release(&buf);
	if (fclose(show_out))
		die_errno(_("failed to close pipe to 'show' for object '%s'"),
			  sha1_to_hex(object));
	if (finish_command(&show))
		die(_("failed to finish 'show' for object '%s'"),
		    sha1_to_hex(object));
