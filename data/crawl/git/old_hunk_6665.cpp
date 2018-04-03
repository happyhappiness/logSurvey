static int delete_tag(const char *name, const char *ref,
				const unsigned char *sha1)
{
	if (delete_ref(ref, sha1))
		return 1;
	printf("Deleted tag '%s'\n", name);
	return 0;
