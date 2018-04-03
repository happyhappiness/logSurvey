	if (reset_type == NONE)
		reset_type = MIXED; /* by default */

	if (reset_type == HARD && is_bare_repository())
		die("hard reset makes no sense in a bare repository");

	/* Soft reset does not touch the index file nor the working tree
	 * at all, but requires them in a good order.  Other resets reset
