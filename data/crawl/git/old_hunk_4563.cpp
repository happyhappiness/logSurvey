static void write_tree_trivial(unsigned char *sha1)
{
	if (write_cache_as_tree(sha1, 0, NULL))
		die("git write-tree failed to write a tree");
}

int try_merge_command(const char *strategy, size_t xopts_nr,
