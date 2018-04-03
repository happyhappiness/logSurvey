	safe_create_leading_directories(path0);
	info_ref_fp = fopen(path1, "w");
	if (!info_ref_fp)
		return error("unable to update %s", path0);
	for_each_ref(add_info_ref, NULL);
	fclose(info_ref_fp);
	adjust_shared_perm(path1);