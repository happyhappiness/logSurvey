	safe_create_leading_directories_const(export_marks_file);
}

static void option_cat_blob_fd(const char *fd)
{
	unsigned long n = ulong_arg("--cat-blob-fd", fd);
	if (n > (unsigned long) INT_MAX)
		die("--cat-blob-fd cannot exceed %d", INT_MAX);
	cat_blob_fd = (int) n;
}

static void option_export_pack_edges(const char *edges)
{
	if (pack_edges)
