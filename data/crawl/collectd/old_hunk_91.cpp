		sstrncpy (vl.type_instance, type_instance, sizeof (vl.type_instance));

	ds = plugin_get_ds (type);
	if (ds == NULL) {
		print_to_socket (fh, "-1 Type `%s' isn't defined.\n", type);
		sfree (identifier_copy);
		return (-1);
	}

	/* Free identifier_copy */
