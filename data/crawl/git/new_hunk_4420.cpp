		strbuf_addch(&(msg->buf), '\n');

	if (get_sha1(arg, object))
		die(_("Failed to resolve '%s' as a valid ref."), arg);
	if (!(buf = read_sha1_file(object, &type, &len)) || !len) {
		free(buf);
		die(_("Failed to read object '%s'."), arg);;
	}
	strbuf_add(&(msg->buf), buf, len);
	free(buf);
