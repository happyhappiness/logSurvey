	return rs;

 invalid:
	die("Invalid refspec '%s'", refspec[i]);
}

struct refspec *parse_fetch_refspec(int nr_refspec, const char **refspec)
{
	return parse_refspec_internal(nr_refspec, refspec, 1);
}

struct refspec *parse_push_refspec(int nr_refspec, const char **refspec)
{
	return parse_refspec_internal(nr_refspec, refspec, 0);
}

static int valid_remote_nick(const char *name)
