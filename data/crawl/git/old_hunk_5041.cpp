	 * affecting the working tree nor HEAD. */
	if (i < argc) {
		if (reset_type == MIXED)
			warning("--mixed option is deprecated with paths.");
		else if (reset_type != NONE)
			die("Cannot do %s reset with paths.",
					reset_type_names[reset_type]);