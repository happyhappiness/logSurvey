	unsigned long size;
	char *data;
	enum object_type type;
	int hit;
	struct strbuf pathbuf = STRBUF_INIT;

	data = read_sha1_file(sha1, &type, &size);
	if (!data) {
		error("'%s': unable to read %s", name, sha1_to_hex(sha1));
		return 0;
	}
	if (opt->relative && opt->prefix_length) {
		quote_path_relative(name + tree_name_len, -1, &pathbuf, opt->prefix);
		strbuf_insert(&pathbuf, 0, name, tree_name_len);
		name = pathbuf.buf;
	}
	hit = grep_buffer(opt, name, data, size);
	strbuf_release(&pathbuf);
	free(data);
	return hit;
}

