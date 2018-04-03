static const char * const git_replace_usage[] = {
	N_("git replace [-f] <object> <replacement>"),
	N_("git replace -d <object>..."),
	N_("git replace [--format=<format>] [-l [<pattern>]]"),
	NULL
};

enum repl_fmt { SHORT, MEDIUM, FULL };

struct show_data {
	const char *pattern;
	enum repl_fmt fmt;
};

static int show_reference(const char *refname, const unsigned char *sha1,
			  int flag, void *cb_data)
{
	struct show_data *data = cb_data;

	if (!fnmatch(data->pattern, refname, 0)) {
		if (data->fmt == SHORT)
			printf("%s\n", refname);
		else if (data->fmt == MEDIUM)
			printf("%s -> %s\n", refname, sha1_to_hex(sha1));
		else { /* data->fmt == FULL */
			unsigned char object[20];
			enum object_type obj_type, repl_type;

			if (get_sha1(refname, object))
				return error("Failed to resolve '%s' as a valid ref.", refname);

			obj_type = sha1_object_info(object, NULL);
			repl_type = sha1_object_info(sha1, NULL);

			printf("%s (%s) -> %s (%s)\n", refname, typename(obj_type),
			       sha1_to_hex(sha1), typename(repl_type));
		}
	}

	return 0;
}

static int list_replace_refs(const char *pattern, const char *format)
{
	struct show_data data;

	if (pattern == NULL)
		pattern = "*";
	data.pattern = pattern;

	if (format == NULL || *format == '\0' || !strcmp(format, "short"))
		data.fmt = SHORT;
	else if (!strcmp(format, "medium"))
		data.fmt = MEDIUM;
	else if (!strcmp(format, "full"))
		data.fmt = FULL;
	else
		die("invalid replace format '%s'\n"
		    "valid formats are 'short', 'medium' and 'full'\n",
		    format);

	for_each_replace_ref(show_reference, (void *) &data);

	return 0;
}
