	if (rename(idx_tmp_name, name_buffer))
		die_errno("unable to rename temporary index file");

	free((void *)idx_tmp_name);
}