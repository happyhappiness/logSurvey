	}
}

static void print_ref_status(char flag, const char *summary, struct ref *to, struct ref *from, const char *msg, int porcelain)
{
	if (porcelain) {
		if (from)
