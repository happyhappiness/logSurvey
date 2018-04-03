	return 0;
}

int create_symref(const char *refname, const char *target, const char *logmsg)
{
	char *lockpath = NULL;
	char buf[1000];
	int fd, len, written;
	char *ref_path = git_pathdup("%s", refname);
	unsigned char old_sha1[20], new_sha1[20];
	struct strbuf err = STRBUF_INIT;

	if (logmsg && read_ref(refname, old_sha1))
		hashclr(old_sha1);

	if (safe_create_leading_directories(ref_path) < 0)
		return error("unable to create directory for %s", ref_path);

#ifndef NO_SYMLINK_HEAD
	if (prefer_symlink_refs) {
		unlink(ref_path);
		if (!symlink(target, ref_path))
			goto done;
		fprintf(stderr, "no symlink - falling back to symbolic ref\n");
	}
#endif

	len = snprintf(buf, sizeof(buf), "ref: %s\n", target);
	if (sizeof(buf) <= len) {
		error("refname too long: %s", target);
		goto error_free_return;
	}
	lockpath = mkpathdup("%s.lock", ref_path);
	fd = open(lockpath, O_CREAT | O_EXCL | O_WRONLY, 0666);
	if (fd < 0) {
		error("Unable to open %s for writing", lockpath);
		goto error_free_return;
	}
	written = write_in_full(fd, buf, len);
	if (close(fd) != 0 || written != len) {
		error("Unable to write to %s", lockpath);
		goto error_unlink_return;
	}
	if (rename(lockpath, ref_path) < 0) {
		error("Unable to create %s", ref_path);
		goto error_unlink_return;
	}
	if (adjust_shared_perm(ref_path)) {
		error("Unable to fix permissions on %s", lockpath);
	error_unlink_return:
		unlink_or_warn(lockpath);
	error_free_return:
		free(lockpath);
		free(ref_path);
		return -1;
	}
	free(lockpath);

#ifndef NO_SYMLINK_HEAD
	done:
#endif
	if (logmsg && !read_ref(target, new_sha1) &&
		log_ref_write(refname, old_sha1, new_sha1, logmsg, 0, &err)) {
		error("%s", err.buf);
		strbuf_release(&err);
	}

	free(ref_path);
	return 0;
}

int reflog_exists(const char *refname)
{
	struct stat st;
