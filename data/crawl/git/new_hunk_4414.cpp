	show.err = 0;
	show.git_cmd = 1;
	if (start_command(&show))
		die(_("unable to start 'show' for object '%s'"),
		    sha1_to_hex(object));

	/* Open the output as FILE* so strbuf_getline() can be used. */
	show_out = xfdopen(show.out, "r");
	if (show_out == NULL)
		die_errno(_("can't fdopen 'show' output fd"));

	/* Prepend "# " to each output line and write result to 'fd' */
	while (strbuf_getline(&buf, show_out, '\n') != EOF) {
