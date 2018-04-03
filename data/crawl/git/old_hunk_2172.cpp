	return ret;
}

int reflog_exists(const char *refname)
{
	struct stat st;