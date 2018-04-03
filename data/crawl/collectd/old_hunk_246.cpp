		return (RET_UNKNOWN);
	}

	for (i = 0; i < ret_ident_num; ++i) {
		char id[1024];

		if ((hostname_g != NULL) && (strcasecmp (hostname_g, ret_ident[i].host)))
			continue;

		status = lcc_identifier_to_string (connection,
				id, sizeof (id), ret_ident + i);
		if (status != 0) {
