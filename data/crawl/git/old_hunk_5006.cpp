		n = slash1 - p;
	else
		n = strlen(p);
	if (!n)
		die("Empty path component found in input");
	if (!slash1 && !S_ISDIR(mode) && subtree)
