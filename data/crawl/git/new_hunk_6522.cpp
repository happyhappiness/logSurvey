	return s.commitable;
}

static int is_a_merge(const unsigned char *sha1)
{
	struct commit *commit = lookup_commit(sha1);
