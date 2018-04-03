			int recurse_limit)
{
	struct tree_desc one;
	void *one_buf;
	enum object_type type;
	unsigned long size;

	one_buf = read_sha1_file(hash1, &type, &size);
	if (!one_buf)
		die("unable to read tree (%s)", sha1_to_hex(hash1));
	if (type != OBJ_TREE)
		die("%s is not a tree", sha1_to_hex(hash1));
	init_tree_desc(&one, one_buf, size);

	while (one.size) {
		const char *path;