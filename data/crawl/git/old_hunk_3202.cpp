		return fdo;
	}
	status = copy_fd(fdi, fdo);
	close(fdi);
	if (close(fdo) != 0)
		return error("%s: close error: %s", dst, strerror(errno));
