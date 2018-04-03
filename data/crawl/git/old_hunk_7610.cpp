	if (reset_type == NONE)
		reset_type = MIXED; /* by default */

	/* Soft reset does not touch the index file nor the working tree
	 * at all, but requires them in a good order.  Other resets reset
	 * the index file to the tree object we are switching to. */
