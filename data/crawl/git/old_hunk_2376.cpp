	return parse_fetch_recurse(opt, arg, 1);
}

static void warn_multiple_config(const unsigned char *commit_sha1,
				 const char *name, const char *option)
{
