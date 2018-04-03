static int show_only;
static unsigned long expire;

static int prune_object(char *path, const char *filename, const unsigned char *sha1)
{
	const char *fullpath = mkpath("%s/%s", path, filename);
