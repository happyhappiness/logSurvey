		c->mode_from_env = 1;
		c->combine = parse_combine_notes_fn(rewrite_mode_env);
		if (!c->combine)
			error("Bad " GIT_NOTES_REWRITE_MODE_ENVIRONMENT
			      " value: '%s'", rewrite_mode_env);
	}
	if (rewrite_refs_env) {
		c->refs_from_env = 1;