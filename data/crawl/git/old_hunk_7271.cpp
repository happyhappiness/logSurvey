	return pos;
}

int add_file_to_index(struct index_state *istate, const char *path, int verbose)
{
	int size, namelen;
