		goto err_ret;
	data = xmallocz(size);
	if (st.st_size != read_in_full(i, data, size)) {
		error_errno(_("'%s': short read"), filename);
		close(i);
		free(data);
		return -1;