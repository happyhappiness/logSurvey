	 */
	if (rename_limit <= 0 || rename_limit > 32767)
		rename_limit = 32767;
	if (num_create > rename_limit && num_src > rename_limit)
		goto cleanup;
	if (num_create * num_src > rename_limit * rename_limit)
		goto cleanup;

	mx = xmalloc(sizeof(*mx) * num_create * num_src);
	for (dst_cnt = i = 0; i < rename_dst_nr; i++) {