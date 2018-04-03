
static int write_entry(struct cache_entry *ce, char *path, const struct checkout *state, int to_tempfile)
{
	int fd;
	long wrote;

	switch (ce->ce_mode & S_IFMT) {
		char *new;
		struct strbuf buf;
		unsigned long size;

	case S_IFREG:
		new = read_blob_entry(ce, path, &size);
		if (!new)
			return error("git checkout-index: unable to read sha1 file of %s (%s)",
				path, sha1_to_hex(ce->sha1));

		/*
		 * Convert from git internal format to working tree format
		 */
		strbuf_init(&buf, 0);
		if (convert_to_working_tree(ce->name, new, size, &buf)) {
			size_t newsize = 0;
			free(new);
			new = strbuf_detach(&buf, &newsize);
			size = newsize;
		}

		if (to_tempfile) {
			strcpy(path, ".merge_file_XXXXXX");
			fd = mkstemp(path);
		} else
			fd = create_file(path, ce->ce_mode);
		if (fd < 0) {
			free(new);
			return error("git checkout-index: unable to create file %s (%s)",
				path, strerror(errno));
		}

		wrote = write_in_full(fd, new, size);
		close(fd);
		free(new);
		if (wrote != size)
			return error("git checkout-index: unable to write file %s", path);
		break;
	case S_IFLNK:
		new = read_blob_entry(ce, path, &size);
		if (!new)
			return error("git checkout-index: unable to read sha1 file of %s (%s)",
				path, sha1_to_hex(ce->sha1));
		if (to_tempfile || !has_symlinks) {
			if (to_tempfile) {
				strcpy(path, ".merge_link_XXXXXX");
				fd = mkstemp(path);
			} else
				fd = create_file(path, 0666);
			if (fd < 0) {
				free(new);
				return error("git checkout-index: unable to create "
						 "file %s (%s)", path, strerror(errno));
			}
			wrote = write_in_full(fd, new, size);
			close(fd);
			free(new);
			if (wrote != size)
				return error("git checkout-index: unable to write file %s",
					path);
		} else {
			wrote = symlink(new, path);
			free(new);
			if (wrote)
				return error("git checkout-index: unable to create "
						 "symlink %s (%s)", path, strerror(errno));
		}
		break;
	case S_IFGITLINK:
		if (to_tempfile)
			return error("git checkout-index: cannot create temporary subproject %s", path);
