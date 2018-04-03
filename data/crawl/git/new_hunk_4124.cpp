	return git_default_config(var, value, cb);
}

static void verify_working_tree_path(unsigned char *head_sha1, const char *path)
{
	unsigned char blob_sha1[20];
	unsigned mode;

	if (!resolve_ref_unsafe("HEAD", head_sha1, 1, NULL))
		die("no such ref: HEAD");
	if (get_tree_entry(head_sha1, path, blob_sha1, &mode))
		die("no such path '%s' in HEAD", path);
	if (sha1_object_info(blob_sha1, NULL) != OBJ_BLOB)
		die("path '%s' in HEAD is not a blob", path);
}

/*
 * Prepare a dummy commit that represents the work tree (or staged) item.
 * Note that annotating work tree item never works in the reverse.
