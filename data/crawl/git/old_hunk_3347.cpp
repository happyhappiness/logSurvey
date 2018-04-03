	if (adjust_shared_perm(idx_tmp_name))
		die_errno("unable to make temporary index file readable");

	sprintf(end_of_name_prefix, "%s.pack", sha1_to_hex(sha1));
	free_pack_by_name(name_buffer);

	if (rename(pack_tmp_name, name_buffer))
		die_errno("unable to rename temporary pack file");

	sprintf(end_of_name_prefix, "%s.idx", sha1_to_hex(sha1));
	if (rename(idx_tmp_name, name_buffer))
		die_errno("unable to rename temporary index file");

	*end_of_name_prefix = '\0';

	free((void *)idx_tmp_name);
}
