		die(_("%s reset is not allowed in a bare repository"),
		    _(reset_type_names[reset_type]));

	/* Soft reset does not touch the index file nor the working tree
	 * at all, but requires them in a good order.  Other resets reset
	 * the index file to the tree object we are switching to. */
