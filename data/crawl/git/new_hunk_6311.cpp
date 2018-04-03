	printf("-%s\n", sha1_to_hex(commit->object.sha1));
}

static inline int log2i(int n)
{
	int log2 = 0;