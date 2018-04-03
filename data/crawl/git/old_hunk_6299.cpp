	return for_each_ref_in("refs/bisect/", register_ref, NULL);
}

static int skipcmp(const void *a, const void *b)
{
	return hashcmp(a, b);
