		write_or_die(fd, tag_template, strlen(tag_template));
		close(fd);

		launch_editor(path, buf);

		unlink(path);
		free(path);
	}

	strbuf_setlen(buf, stripspace(buf->buf, buf->len, 1));

	if (!message && !buf->len)
		die("no tag message?");

	/* insert the header and add the '\n' if needed: */
	if (buf->len)
		strbuf_addch(buf, '\n');
	strbuf_insert(buf, 0, header_buf, header_len);

	if (sign && do_sign(buf) < 0)
		die("unable to sign the tag");
	if (write_sha1_file(buf->buf, buf->len, tag_type, result) < 0)
		die("unable to write tag file");
}

int cmd_tag(int argc, const char **argv, const char *prefix)
{
	struct strbuf buf;
	unsigned char object[20], prev[20];
	int annotate = 0, sign = 0, force = 0, lines = 0, message = 0;
	char ref[PATH_MAX];
	const char *object_ref, *tag;
	int i;
	struct ref_lock *lock;

	git_config(git_tag_config);
	strbuf_init(&buf, 0);

	for (i = 1; i < argc; i++) {
		const char *arg = argv[i];