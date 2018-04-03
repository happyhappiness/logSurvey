	return refs;
}

static int fetch_dumb(int nr_heads, struct ref **to_fetch)
{
	char **targets = xmalloc(nr_heads * sizeof(char*));
