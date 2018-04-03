	self_destruct();
    GetInteger(i);
    size = i << 10;		/* Mbytes to kbytes */
    GetInteger(i);
    l1 = i;
    GetInteger(i);
    l2 = i;
    if ((token = strtok(NULL, w_space)))
	if (!strcasecmp(token, "read-only"))
	    readonly = 1;