	return 0;
    }
    type = get_token(fp, token);
    if (type != STATUS) {
	print_error("Should be STATUS", token, nexttype);
	free_node(np);
	return 0;