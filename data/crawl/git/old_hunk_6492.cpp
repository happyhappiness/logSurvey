#include "string-list.h"
#include "mailmap.h"

const char *git_mailmap_file;
static int read_single_mailmap(struct string_list *map, const char *filename, char **repo_abbrev)
{
	char buffer[1024];
