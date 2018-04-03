		*value = STATUS_FORMAT_PORCELAIN;
	else if (!strcmp(arg, "v1") || !strcmp(arg, "1"))
		*value = STATUS_FORMAT_PORCELAIN;
	else
		die("unsupported porcelain version '%s'", arg);

