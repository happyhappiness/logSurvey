	return git_default_config(var, value, cb);
}

static struct commit *find_single_final(struct rev_info *revs,
					const char **name_p)
{