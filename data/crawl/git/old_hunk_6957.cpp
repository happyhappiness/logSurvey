	const char *ren2_dst = ren2->pair->two->path;
	const char *dst_name1 = ren1_dst;
	const char *dst_name2 = ren2_dst;
	if (path_list_has_path(&current_directory_set, ren1_dst)) {
		dst_name1 = del[delp++] = unique_path(ren1_dst, branch1);
		output(1, "%s is a directory in %s added as %s instead",
		       ren1_dst, branch2, dst_name1);
		remove_file(0, ren1_dst, 0);
	}
	if (path_list_has_path(&current_directory_set, ren2_dst)) {
		dst_name2 = del[delp++] = unique_path(ren2_dst, branch2);
		output(1, "%s is a directory in %s added as %s instead",
		       ren2_dst, branch1, dst_name2);
