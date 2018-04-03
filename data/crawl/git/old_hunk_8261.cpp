		return fdo;
	}
	status = copy_fd(fdi, fdo);
	close(fdo);

	if (!status && adjust_shared_perm(dst))
		return -1;
