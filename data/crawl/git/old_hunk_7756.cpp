	if (!editor)
		editor = "vi";

	if (!strcmp(editor, ":"))
		return;

	memset(&child, 0, sizeof(child));
	child.argv = args;
	args[0] = editor;
	args[1] = path;
	args[2] = NULL;

	if (run_command(&child))
		die("There was a problem with the editor %s.", editor);

	if (strbuf_read_file(buffer, path, 0) < 0)
		die("could not read message file '%s': %s",