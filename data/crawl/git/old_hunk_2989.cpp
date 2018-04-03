static void am_setup(struct am_state *state, enum patch_format patch_format,
			const char **paths)
{
	if (mkdir(state->dir, 0777) < 0 && errno != EEXIST)
		die_errno(_("failed to create directory '%s'"), state->dir);
