	return 0;
}

/**
 * Applies all queued mail.
 */
static void am_run(struct am_state *state)
{
	refresh_and_write_cache();

	while (state->cur <= state->last) {
