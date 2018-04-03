#include "tag.h"

static int is_shallow = -1;
static struct stat shallow_stat;
static char *alternate_shallow_file;

void set_alternate_shallow_file(const char *path)
{
	if (is_shallow != -1)
		die("BUG: is_repository_shallow must not be called before set_alternate_shallow_file");
	free(alternate_shallow_file);
	alternate_shallow_file = path ? xstrdup(path) : NULL;
}

int register_shallow(const unsigned char *sha1)
{
