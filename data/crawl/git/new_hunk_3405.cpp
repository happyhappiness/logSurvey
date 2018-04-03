	if (rename(idx_tmp_name, name_buffer))
		die_errno("unable to rename temporary index file");

	*end_of_name_prefix = '\0';

	free((void *)idx_tmp_name);
}