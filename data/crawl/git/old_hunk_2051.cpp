		goto err_ret;
	data = xmallocz(size);
	if (st.st_size != read_in_full(i, data, size)) {
		error(_("'%s': short read %s"), filename, strerror(errno));
		close(i);
		free(data);
		return -1;