		free(del[delp]);
}

static void conflict_rename_dir(struct rename *ren1,
				const char *branch1)
{
	char *new_path = unique_path(ren1->pair->two->path, branch1);
	output(1, "Renaming %s to %s instead", ren1->pair->one->path, new_path);
	remove_file(0, ren1->pair->two->path, 0);
	update_file(0, ren1->pair->two->sha1, ren1->pair->two->mode, new_path);
	free(new_path);
}

static void conflict_rename_rename_2(struct rename *ren1,
				     const char *branch1,
				     struct rename *ren2,
				     const char *branch2)
{
	char *new_path1 = unique_path(ren1->pair->two->path, branch1);
	char *new_path2 = unique_path(ren2->pair->two->path, branch2);
	output(1, "Renaming %s to %s and %s to %s instead",
	       ren1->pair->one->path, new_path1,
	       ren2->pair->one->path, new_path2);
	remove_file(0, ren1->pair->two->path, 0);
