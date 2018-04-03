#include "cache.h"
#include "string-list.h"

void write_list(const struct string_list *list)
{
	int i;
	for (i = 0; i < list->nr; i++)
		printf("[%d]: \"%s\"\n", i, list->items[i].string);
}

int main(int argc, char **argv)
{
	if (argc == 5 && !strcmp(argv[1], "split")) {
