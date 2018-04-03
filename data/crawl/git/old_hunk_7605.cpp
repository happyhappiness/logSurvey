	return str;
}

static void decode_tree_entry(struct tree_desc *desc, const void *buf, unsigned long size)
{
	const char *path;
	unsigned int mode, len;

	path = get_mode(buf, &mode);
	if (!path)
		die("corrupt tree file");
	len = strlen(path) + 1;
