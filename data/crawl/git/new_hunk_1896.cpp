	char **targets = xmalloc(nr_heads * sizeof(char*));
	int ret, i;

	if (options.depth || options.deepen_since)
		die("dumb http transport does not support shallow capabilities");
	for (i = 0; i < nr_heads; i++)
		targets[i] = xstrdup(oid_to_hex(&to_fetch[i]->old_oid));

