	 * affecting the working tree nor HEAD. */
	if (i < argc) {
		if (reset_type == MIXED)
			warning("--mixed with paths is deprecated; use 'git reset -- <paths>' instead.");
		else if (reset_type != NONE)
			die("Cannot do %s reset with paths.",
					reset_type_names[reset_type]);
