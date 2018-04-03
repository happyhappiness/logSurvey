	return 0;
}

int notes_copy_from_stdin(int force)
{
	struct strbuf buf = STRBUF_INIT;
	struct notes_tree *t;
	int ret = 0;

	init_notes(NULL, NULL, NULL, 0);
	t = &default_notes_tree;

	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
		unsigned char from_obj[20], to_obj[20];
