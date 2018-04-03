	return write_shallow_commits_1(out, use_pack_protocol, extra, 0);
}

char *setup_temporary_shallow(const struct sha1_array *extra)
{
	struct strbuf sb = STRBUF_INIT;
	int fd;

	if (write_shallow_commits(&sb, 0, extra)) {
		struct strbuf path = STRBUF_INIT;
		strbuf_addstr(&path, git_path("shallow_XXXXXX"));
		fd = xmkstemp(path.buf);
		if (write_in_full(fd, sb.buf, sb.len) != sb.len)
			die_errno("failed to write to %s",
				  path.buf);
		close(fd);
		strbuf_release(&sb);
		return strbuf_detach(&path, NULL);
	}
	/*
	 * is_repository_shallow() sees empty string as "no shallow
	 * file".
	 */
	return xstrdup("");
}

void setup_alternate_shallow(struct lock_file *shallow_lock,
