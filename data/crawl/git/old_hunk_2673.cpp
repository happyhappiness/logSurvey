	return fsck_obj(obj);
}

static inline int is_loose_object_file(struct dirent *de,
				       char *name, unsigned char *sha1)
{
	if (strlen(de->d_name) != 38)
		return 0;
	memcpy(name + 2, de->d_name, 39);
	return !get_sha1_hex(name, sha1);
}

static void fsck_dir(int i, char *path)
{
	DIR *dir = opendir(path);
	struct dirent *de;
	char name[100];

	if (!dir)
		return;

	if (verbose)
		fprintf(stderr, "Checking directory %s\n", path);

	sprintf(name, "%02x", i);
	while ((de = readdir(dir)) != NULL) {
		unsigned char sha1[20];

		if (is_dot_or_dotdot(de->d_name))
			continue;
		if (is_loose_object_file(de, name, sha1)) {
			if (fsck_sha1(sha1))
				errors_found |= ERROR_OBJECT;
			continue;
		}
		if (starts_with(de->d_name, "tmp_obj_"))
			continue;
		fprintf(stderr, "bad sha1 file: %s/%s\n", path, de->d_name);
	}
	closedir(dir);
}

static int default_refs;

static void fsck_handle_reflog_sha1(const char *refname, unsigned char *sha1)
