	if (*ep == ',')
		*base = ep + 1;
	else if (*ep)
		die("unrecognized reflog param '%s'", arg + 9);
	else
		*base = NULL;
	if (*cnt <= 0)