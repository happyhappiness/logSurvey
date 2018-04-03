	return git_default_config(var, value, cb);
}

static int too_many_loose_objects(void)
{
	/*
