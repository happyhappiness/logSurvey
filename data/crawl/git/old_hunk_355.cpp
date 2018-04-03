				   DIFF_NEW_NAME);
}

static int gitdiff_oldmode(struct apply_state *state,
			   const char *line,
			   struct patch *patch)
{
	patch->old_mode = strtoul(line, NULL, 8);
	return 0;
}

static int gitdiff_newmode(struct apply_state *state,
			   const char *line,
			   struct patch *patch)
{
	patch->new_mode = strtoul(line, NULL, 8);
	return 0;
}

static int gitdiff_delete(struct apply_state *state,