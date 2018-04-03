	}
	nexttype = get_token(fp, nexttoken);
    }
    if (nexttype != ACCESS) {
	print_error("Should be ACCESS", nexttoken, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != READONLY && type != READWRITE && type != WRITEONLY
	&& type != NOACCESS && type != READCREATE) {
	print_error("Bad access type", nexttoken, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != STATUS) {
	print_error("Should be STATUS", token, nexttype);
	free_node(np);
	return 0;
    }
    type = get_token(fp, token);
    if (type != MANDATORY && type != CURRENT && type != OPTIONAL && type != OBSOLETE && type != DEPRECATED) {
	print_error("Bad status", token, type);
	free_node(np);
	return 0;
