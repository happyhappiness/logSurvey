	struct ref_list references;
};

/* returns an fd */
static int read_header(const char *path, struct bundle_header *header) {
	char buffer[1024];
	int fd;
	long fpos;
	FILE *ffd = fopen(path, "rb");

	if (!ffd)
		return error("could not open '%s'", path);
	if (!fgets(buffer, sizeof(buffer), ffd) ||
			strcmp(buffer, bundle_signature)) {
		fclose(ffd);
		return error("'%s' does not look like a v2 bundle file", path);
	}
	while (fgets(buffer, sizeof(buffer), ffd)
			&& buffer[0] != '\n') {
		int is_prereq = buffer[0] == '-';
		int offset = is_prereq ? 1 : 0;
