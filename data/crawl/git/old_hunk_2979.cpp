static void am_run(struct am_state *state)
{
	const char *argv_gc_auto[] = {"gc", "--auto", NULL};

	refresh_and_write_cache();

	while (state->cur <= state->last) {
		const char *mail = am_path(state, msgnum(state));
