{
	int *recurse_submodules = opt->value;

	if (*recurse_submodules != RECURSE_SUBMODULES_DEFAULT)
		die("%s can only be used once.", opt->long_name);

	if (unset)
		*recurse_submodules = RECURSE_SUBMODULES_OFF;
	else if (arg)
