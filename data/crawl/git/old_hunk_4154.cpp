	return do_change_note_fanout(root, root, hex_sha1, 0, path, 0, fanout);
}

static void file_change_m(struct branch *b)
{
	const char *p = command_buf.buf + 2;
