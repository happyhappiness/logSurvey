{
	char *new_path1 = unique_path(ren1->pair->two->path, branch1);
	char *new_path2 = unique_path(ren2->pair->two->path, branch2);
	output(1, "Renamed %s to %s and %s to %s instead",
	       ren1->pair->one->path, new_path1,
	       ren2->pair->one->path, new_path2);
	remove_file(0, ren1->pair->two->path, 0);
