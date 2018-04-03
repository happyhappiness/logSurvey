	result = log_ref_write_fd(logfd, old_sha1, new_sha1,
				  git_committer_info(0), msg);
	if (result) {
		int save_errno = errno;
		close(logfd);
		error("Unable to append to %s", log_file);
		errno = save_errno;
		return -1;
	}
	if (close(logfd)) {
		int save_errno = errno;
		error("Unable to append to %s", log_file);
		errno = save_errno;
		return -1;
	}
	return 0;
}

static int log_ref_write(const char *refname, const unsigned char *old_sha1,
			 const unsigned char *new_sha1, const char *msg)
{
	struct strbuf sb = STRBUF_INIT;
	int ret = log_ref_write_1(refname, old_sha1, new_sha1, msg, &sb);
	strbuf_release(&sb);
	return ret;
}
