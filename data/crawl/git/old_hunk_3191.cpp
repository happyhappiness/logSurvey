	return branch->merge[0]->dst;
}

static int ignore_symref_update(const char *refname)
{
	unsigned char sha1[20];
