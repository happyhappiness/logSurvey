	return updated;
}

static void show_file(const char * fmt, const char * name, int in_porcelain,
		      int * first, char *header_msg)
{
	if (in_porcelain && *first && header_msg) {
		printf("%s\n", header_msg);
		*first=0;
	}
	printf(fmt, name);
}

int refresh_index(struct index_state *istate, unsigned int flags, const char **pathspec,
		  char *seen, char *header_msg)
{
	int i;
	int has_errors = 0;
