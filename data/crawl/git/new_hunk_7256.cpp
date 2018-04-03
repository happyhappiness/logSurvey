	return rs;

 invalid:
	if (verify) {
		free(rs);
		return NULL;
	}
	die("Invalid refspec '%s'", refspec[i]);
}

int valid_fetch_refspec(const char *fetch_refspec_str)
{
	const char *fetch_refspec[] = { fetch_refspec_str };
	struct refspec *refspec;

	refspec = parse_refspec_internal(1, fetch_refspec, 1, 1);
	if (refspec)
		free(refspec);
	return !!refspec;
}

struct refspec *parse_fetch_refspec(int nr_refspec, const char **refspec)
{
	return parse_refspec_internal(nr_refspec, refspec, 1, 0);
}

struct refspec *parse_push_refspec(int nr_refspec, const char **refspec)
{
	return parse_refspec_internal(nr_refspec, refspec, 0, 0);
}

static int valid_remote_nick(const char *name)
