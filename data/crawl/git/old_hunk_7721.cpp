
static const char prune_usage[] = "git-prune [-n]";
static int show_only;

static int prune_object(char *path, const char *filename, const unsigned char *sha1)
{
	if (show_only) {
		enum object_type type = sha1_object_info(sha1, NULL);
		printf("%s %s\n", sha1_to_hex(sha1),
		       (type > 0) ? typename(type) : "unknown");
	} else
		unlink(mkpath("%s/%s", path, filename));
	return 0;
}

