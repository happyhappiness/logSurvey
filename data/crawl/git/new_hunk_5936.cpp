		 */
		if (errno == EPIPE || errno == EINVAL)
			exit(0);
		die_errno("write failure on '%s'", desc);
	}
}

void fsync_or_die(int fd, const char *msg)
{
	if (fsync(fd) < 0) {
		die_errno("fsync error on '%s'", msg);
	}
}

