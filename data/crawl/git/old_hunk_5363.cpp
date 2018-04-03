	return isalnum(ch) || ch == '_';
}

static void show_name(struct grep_opt *opt, const char *name)
{
	opt->output(opt, name, strlen(name));
	opt->output(opt, opt->null_following_name ? "\0" : "\n", 1);
}

