	return ret;
}

int git_config_from_buf(config_fn_t fn, const char *name, const char *buf,
			size_t len, void *data)
{
	struct config_source top;

	top.u.buf.buf = buf;
	top.u.buf.len = len;
	top.u.buf.pos = 0;
	top.name = name;
	top.fgetc = config_buf_fgetc;
	top.ungetc = config_buf_ungetc;
	top.ftell = config_buf_ftell;

	return do_config_from(&top, fn, data);
}

static int git_config_from_blob_sha1(config_fn_t fn,
				     const char *name,
				     const unsigned char *sha1,
				     void *data)
{
	enum object_type type;
	char *buf;
	unsigned long size;
	int ret;

	buf = read_sha1_file(sha1, &type, &size);
	if (!buf)
		return error("unable to load config blob object '%s'", name);
	if (type != OBJ_BLOB) {
		free(buf);
		return error("reference '%s' does not point to a blob", name);
	}

	ret = git_config_from_buf(fn, name, buf, size, data);
	free(buf);

	return ret;
}

static int git_config_from_blob_ref(config_fn_t fn,
				    const char *name,
				    void *data)
{
	unsigned char sha1[20];

	if (get_sha1(name, sha1) < 0)
		return error("unable to resolve config blob '%s'", name);
	return git_config_from_blob_sha1(fn, name, sha1, data);
}

const char *git_etc_gitconfig(void)
{
	static const char *system_wide;
