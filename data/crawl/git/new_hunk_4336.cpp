	return git_config_set_multivar(key, tmp->buf, "^$", 0);
}

static const char mirror_advice[] =
"--mirror is dangerous and deprecated; please\n"
"\t use --mirror=fetch or --mirror=push instead";

static int parse_mirror_opt(const struct option *opt, const char *arg, int not)
{
	unsigned *mirror = opt->value;
	if (not)
		*mirror = MIRROR_NONE;
	else if (!arg) {
		warning("%s", mirror_advice);
		*mirror = MIRROR_BOTH;
	}
	else if (!strcmp(arg, "fetch"))
		*mirror = MIRROR_FETCH;
	else if (!strcmp(arg, "push"))