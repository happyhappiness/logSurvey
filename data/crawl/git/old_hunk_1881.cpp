	/* no need to be strict, transport_set_option() will validate it again */
	if (depth && atoi(depth) < 1)
		die(_("depth %s is not a positive number"), depth);
	if (depth || deepen_since)
		deepen = 1;

	if (recurse_submodules != RECURSE_SUBMODULES_OFF) {
