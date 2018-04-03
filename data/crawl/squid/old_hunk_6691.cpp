    debug(3) fprintf(stderr, "cmgr: decoded host: '%s'\n", host_name);
    if ((time_str = strtok(NULL, "|")) == NULL)
	return;
    debug(3) fprintf(stderr, "cmgr: decoded time: '%s' (now: %d)\n", time_str, (int)now);
    if ((user_name = strtok(NULL, "|")) == NULL)
	return;
    debug(3) fprintf(stderr, "cmgr: decoded uname: '%s'\n", user_name);
