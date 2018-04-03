static void write_filename_info(const char *path)
{
	printf("filename ");
	write_name_quoted(NULL, 0, path, 1, stdout);
	putchar('\n');
}

/*
