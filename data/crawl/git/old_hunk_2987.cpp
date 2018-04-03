 */
static void am_next(struct am_state *state)
{
	state->cur++;
	write_file(am_path(state, "next"), 1, "%d", state->cur);
}

/**
 * Applies all queued mail.
 */
static void am_run(struct am_state *state)
{
	while (state->cur <= state->last) {

		/* NEEDSWORK: Patch application not implemented yet */

		am_next(state);
	}
