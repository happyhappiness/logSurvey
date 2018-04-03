	self_destruct();
    GetInteger(i);
    size = i << 10;		/* Mbytes to kbytes */
    if (size <= 0)
	fatal("parse_cachedir: invalid size value");
    GetInteger(i);
    l1 = i;
    if (l1 <= 0)
	fatal("parse_cachedir: invalid level 1 directories value");
    GetInteger(i);
    l2 = i;
    if (l2 <= 0)
	fatal("parse_cachedir: invalid level 2 directories value");
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    readonly = 1;