	fatal("parse_cachedir: invalid level 2 directories value");
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    readonly = 1;
    for (i = 0; i < swap->n_configured; i++) {
	tmp = swap->swapDirs + i;
	if (!strcmp(path, tmp->path)) {
