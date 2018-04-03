static int grep_source_load(struct grep_source *gs);
static int grep_source_is_binary(struct grep_source *gs);


static struct grep_pat *create_grep_pat(const char *pat, size_t patlen,
					const char *origin, int no,
