struct batch_options {
	int enabled;
	int print_contents;
};

static int batch_one_object(const char *obj_name, struct batch_options *opt)
{
	unsigned char sha1[20];
	enum object_type type = 0;
	unsigned long size;

	if (!obj_name)
	   return 1;

	if (get_sha1(obj_name, sha1)) {
		printf("%s missing\n", obj_name);
		fflush(stdout);
		return 0;
	}

	type = sha1_object_info(sha1, &size);
	if (type <= 0) {
		printf("%s missing\n", obj_name);
		fflush(stdout);
		return 0;
	}

	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);
	fflush(stdout);

	if (opt->print_contents) {
		print_object_or_die(1, sha1, type, size);
		write_or_die(1, "\n", 1);
	}
	return 0;
