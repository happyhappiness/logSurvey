}

/*
 * To allow LF and other nonportable characters in pathnames,
 * they are c-style quoted as needed.
 */
static void write_filename_info(const char *path)
{
	printf("filename ");
	write_name_quoted(path, stdout, '\n');
}

/*
