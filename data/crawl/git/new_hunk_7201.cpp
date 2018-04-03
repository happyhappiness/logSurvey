	return 0;
}

static int batch_one_object(const char *obj_name)
{
	unsigned char sha1[20];
	enum object_type type;
	unsigned long size;

	if (!obj_name)
	   return 1;

	if (get_sha1(obj_name, sha1)) {
		printf("%s missing\n", obj_name);
		return 0;
	}

	type = sha1_object_info(sha1, &size);
	if (type <= 0)
		return 1;

	printf("%s %s %lu\n", sha1_to_hex(sha1), typename(type), size);

	return 0;
}

static int batch_objects(void)
{
	struct strbuf buf;

	strbuf_init(&buf, 0);
	while (strbuf_getline(&buf, stdin, '\n') != EOF) {
		int error = batch_one_object(buf.buf);
		if (error)
			return error;
	}

	return 0;
}

static const char cat_file_usage[] = "git-cat-file [ [-t|-s|-e|-p|<type>] <sha1> | --batch-check < <list_of_sha1s> ]";

int cmd_cat_file(int argc, const char **argv, const char *prefix)
{
	int i, opt = 0, batch_check = 0;
	const char *exp_type = NULL, *obj_name = NULL;

	git_config(git_default_config);

	for (i = 1; i < argc; ++i) {
		const char *arg = argv[i];

		if (!strcmp(arg, "--batch-check")) {
			if (opt) {
				error("git-cat-file: Can't use --batch-check with -%c", opt);
				usage(cat_file_usage);
			} else if (exp_type) {
				error("git-cat-file: Can't use --batch-check when a type (\"%s\") is specified", exp_type);
				usage(cat_file_usage);
			} else if (obj_name) {
				error("git-cat-file: Can't use --batch-check when an object (\"%s\") is specified", obj_name);
				usage(cat_file_usage);
			}

			batch_check = 1;
			continue;
		}

		if (!strcmp(arg, "-t") || !strcmp(arg, "-s") || !strcmp(arg, "-e") || !strcmp(arg, "-p")) {
			if (batch_check) {
				error("git-cat-file: Can't use %s with --batch-check", arg);
				usage(cat_file_usage);
			}

			exp_type = arg;
			opt = exp_type[1];
			continue;
