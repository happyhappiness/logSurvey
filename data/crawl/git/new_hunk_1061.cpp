	return 0;
}

static int print_alternate(struct alternate_object_database *alt, void *data)
{
	printf("alternate: ");
	quote_c_style(alt->path, NULL, stdout, 0);
	putchar('\n');
	return 0;
}

static char const * const count_objects_usage[] = {
	N_("git count-objects [-v] [-H | --human-readable]"),
	NULL
