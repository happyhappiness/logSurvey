		die_errno("Full write to remote helper failed");
}

static const char *remove_ext_force(const char *url)
{
	if (url) {
		const char *colon = strchr(url, ':');