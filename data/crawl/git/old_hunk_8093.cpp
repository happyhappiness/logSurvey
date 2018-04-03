
int main(int argc, char **argv)
{
	unsigned long size = 4096;
	char *buffer = xmalloc(size);
	unsigned char result_sha1[20];

	if (argc != 1)
		usage("git-mktag < signaturefile");

	setup_git_directory();

	if (read_fd(0, &buffer, &size)) {
		free(buffer);
		die("could not read from stdin");
	}

	/* Verify it for some basic sanity: it needs to start with
	   "object <sha1>\ntype\ntagger " */
	if (verify_tag(buffer, size) < 0)
		die("invalid tag signature file");

	if (write_sha1_file(buffer, size, tag_type, result_sha1) < 0)
		die("unable to write tag file");

	free(buffer);

	printf("%s\n", sha1_to_hex(result_sha1));
	return 0;
}
