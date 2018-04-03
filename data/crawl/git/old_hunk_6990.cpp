	return git_default_config(var, value, cb);
}

static int write_tar_entry(const unsigned char *sha1, const char *base,
		int baselen, const char *filename, unsigned mode, int stage,
		void *context)
{
	static struct strbuf path = STRBUF_INIT;
	void *buffer;
	enum object_type type;
	unsigned long size;

	strbuf_reset(&path);
	strbuf_grow(&path, PATH_MAX);
	strbuf_add(&path, base, baselen);
	strbuf_addstr(&path, filename);
	if (is_archive_path_ignored(path.buf + base_len))
		return 0;
	if (S_ISDIR(mode) || S_ISGITLINK(mode)) {
		strbuf_addch(&path, '/');
		buffer = NULL;
		size = 0;
	} else {
		buffer = sha1_file_to_archive(path.buf + base_len, sha1, mode,
				&type, &size, commit);
		if (!buffer)
			die("cannot read %s", sha1_to_hex(sha1));
	}

	write_entry(sha1, &path, mode, buffer, size);
	free(buffer);

	return READ_TREE_RECURSIVE;
}

int write_tar_archive(struct archiver_args *args)
{
	git_config(git_tar_config, NULL);

	archive_time = args->time;
	verbose = args->verbose;
	commit = args->commit;
	base_len = args->baselen;

	if (args->commit_sha1)
		write_global_extended_header(args->commit_sha1);

	if (args->baselen > 0 && args->base[args->baselen - 1] == '/') {
		char *base = xstrdup(args->base);
		int baselen = strlen(base);

		while (baselen > 0 && base[baselen - 1] == '/')
			base[--baselen] = '\0';
		write_tar_entry(args->tree->object.sha1, "", 0, base, 040777,
				0, NULL);
		free(base);
	}
	read_tree_recursive(args->tree, args->base, args->baselen, 0,
			    args->pathspec, write_tar_entry, NULL);
	write_trailer();

	return 0;
}
