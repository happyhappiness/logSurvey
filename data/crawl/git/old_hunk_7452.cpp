	return 0;
}

static int peel_onion(const char *name, int len, unsigned char *sha1)
{
	unsigned char outer[20];
