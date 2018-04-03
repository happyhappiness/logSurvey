	return updated;
}

int refresh_index(struct index_state *istate, unsigned int flags, const char **pathspec, char *seen)
{
	int i;
	int has_errors = 0;
