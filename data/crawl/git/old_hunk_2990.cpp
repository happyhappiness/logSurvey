	strbuf_release(&sb);
}

/**
 * Setup a new am session for applying patches
 */
static void am_setup(struct am_state *state)
{
	if (mkdir(state->dir, 0777) < 0 && errno != EEXIST)
		die_errno(_("failed to create directory '%s'"), state->dir);

	/*
	 * NOTE: Since the "next" and "last" files determine if an am_state
	 * session is in progress, they should be written last.
