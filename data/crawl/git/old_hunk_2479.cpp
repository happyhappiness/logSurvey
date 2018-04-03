		      int always, int allow_undefined, int name_only)
{
	const char *name;
	const unsigned char *sha1 = get_object_hash(*obj);

	if (!name_only)
		printf("%s ", caller_name ? caller_name : sha1_to_hex(sha1));
	name = get_rev_name(obj);
	if (name)
		printf("%s\n", name);
	else if (allow_undefined)
		printf("undefined\n");
	else if (always)
		printf("%s\n", find_unique_abbrev(sha1, DEFAULT_ABBREV));
	else
		die("cannot describe '%s'", sha1_to_hex(sha1));
}

static char const * const name_rev_usage[] = {
