
static void show_edge(struct commit *commit)
{
	printf("-%s\n", sha1_to_hex(commit->object.sha1));
}

static void print_var_str(const char *var, const char *val)
